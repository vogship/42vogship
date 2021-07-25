# Check version online
curl -L -o vogship-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/version-check 2>> ./install-dump

error-print() {
  cat vogShip >> ./install-dump
  rm vogship
  cp install-dump download-err.log
  echo -e "\e[90m---"
  echo -e "\e[97mThere was a problem downloading the Vogship."
  echo -e "\e[90m---"
  echo -e "\e[96mIf problems persist, post an issue on the github repo."
  echo -e "\e[96mJust remember to post your \e[91mdownload-err.log\e[96m file"
  echo -e "\e[96mfound in this Directory.\e[0m"
  echo -e "\e[37m(\e[94mhttps://github.com/IsCoffeeTho/42vogship/issues/new\e[37m)"
}

if grep -q 'vogShip v1' 'vogship-check';
then
  echo -e "\e[97mDownloading the Vogship..."
  curl -L -o vogship https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/commands.sh 2>> ./install-dump
  if grep -q '# vogShip v1' "vogship";
  then
    echo -e "\e[90m---"
    echo -e "\e[97mInstalling the Vogship..."
    mv vogship ~/.zshrc
    source ~/.zshrc
    rm -rf Installer.sh 
  else
    error-print
  fi
else
  error-print
fi

rm -rf install-dump