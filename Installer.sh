#!/bin/bash
echo -e "\e[90mSearching for the Vogship...\e[0m"
curl -s -L -o vogship-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/version-check
if grep -q 'vogShip' 'vogship-check';
then
  curl -s -L -o vogship https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/commands.sh
  if grep -q ".*# vogShip .*" "vogship";
  then
    echo -e "\e[90m---\[0m"
    if grep -q "# vogShip" "~/.bashrc";
    then
      echo -e "\e[97mCleaning Environment...\e[0m"
      rm -rf ~/.zshrc
    fi
    echo -e "\e[97mPlacing...\e[0m"
    mv -f vogship ~/.bashrc
    echo -e "\e[97mVerifying...\e[0m"
    chmod a+x ~/.bashrc
    echo -e "\e[97mInstalling the Vogship...\e[0m"
    source ~/.bashrc
    echo -e "\e[97mInstallation Complete.\e[0m"
    rm -rf $0
  else
    mv vogShip install-dump
    rm vogship
    cp install-dump download-err.log
    echo -e '\e[96mCreated \e[91mdownload-err.log\e[96m file\e[0m"
    echo -e '\e[91mThere is a problem trying to find vogShip\e[0m"
  fi
else
  echo -e "\e[91mCannot connect to the Internet\e[0m"
fi
rm -rf vogship-check
rm -rf install-dump
