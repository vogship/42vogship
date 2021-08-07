#!/bin/zsh
echo -e '\e[90mSearching for the Vogship...'
curl -s -L --trace-ascii install-dump -o vogship-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/version-check
if grep -q 'vogShip' 'vogship-check';
then
  echo -e '\e[97mDownloading the Vogship...'
  curl -s -L --trace-ascii install-dump -o vogship https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/commands.sh 1&2>> ./install-dump
  if grep -q '# vogShip ' "vogship";
  then
    echo -e '\e[90m---'
    echo -e '\e[97mCleaning Environment...'
    rm -rf ~/.zshrc
    echo -e '\e[97mPlacing...'
    mv -f vogship ~/.zshrc
    echo -e '\e[97mVerifying...'
    chmod a+x ~/.zshrc
    echo -e '\e[97mInstalling the Vogship...'
    source ~/.zshrc
    echo -e '\e[97mInstallation Complete.'
    rm -rf $0
  else
    errorPrint
  fi
else
  errorPrint
fi
rm -rf vogship-check
rm -rf install-dump
errorPrint() {
  mv vogShip install-dump
  rm vogship
  cp install-dump download-err.log
  echo -e '\e[90m---'
  echo -e '\e[97mThere was a problem downloading the Vogship.'
  echo -e '\e[90m---'
  echo -e '\e[96mIf problems persist, post an issue on the github repo.'
  echo -e '\e[96mJust remember to post your \e[91mdownload-err.log\e[96m file'
  echo -e '\e[96mfound in this Directory.\e[0m'
  echo -e '\e[37m(\e[94mhttps://github.com/IsCoffeeTho/42vogship/issues/new\e[37m)'
}