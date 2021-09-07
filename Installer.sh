#!/bin/bash
echo -e '\e[90mSearching for the Vogship...'
curl -s -L -o vogship-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/version-check
if grep -q 'vogShip' 'vogship-check';
then
  curl -s -L -o vogship https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/commands.sh
  if grep -q ".*# vogShip .*" "vogship";
  then
    echo -e '\e[90m---'
    if grep -q "# vogShip" "~/.bashrc";
    then
      echo -e '\e[97mCleaning Environment...'
      rm -rf ~/.zshrc
    fi
    echo -e '\e[97mPlacing...'
    mv -f vogship ~/.bashrc
    echo -e '\e[97mVerifying...'
    chmod a+x ~/.bashrc
    echo -e '\e[97mInstalling the Vogship...'
    source ~/.bashrc
    echo -e '\e[97mInstallation Complete.'
    rm -rf $0
  else
    mv vogShip install-dump
    rm vogship
    cp install-dump download-err.log
    echo -e '\e[96mCreated \e[91mdownload-err.log\e[96m file'
    echo -e '\e[91mThere is a problem trying to find vogShip'
  fi
else
  echo -e '\e[91mCannot connect to the Internet'
fi
rm -rf vogship-check
rm -rf install-dump
