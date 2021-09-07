#!/bin/bash
echo -e '\e[90mSearching for the Vogship...'
curl -L -o vogship-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/version-check
if grep -q 'vogShip' 'vogship-check';
then
  echo -e '\e[92mcurling commands'
  curl -L -o vogship https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/commands.sh 1&2>> ./install-dump
  if grep -q "# vogShip " "vogship";
  then
    echo -e '\e[90m---'
    if grep -q "# vogShip " "~/.zshrc";
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
  echo -e '\e[92mcurling google'
  curl -s -L http://google.com
  if [ $? -eq 0 ]; then
      mv vogShip install-dump
      rm vogship
      cp install-dump download-err.log
      echo -e '\e[96mCreated \e[91mdownload-err.log\e[96m file'
      echo -e '\e[91mThere is a problem trying to find vogShip,'
      echo -e '\e[91mWatchout for firewalls or proxies.'
  else
      echo -e '\e[91mCannot connect to the Internet'
  fi
fi
rm -rf vogship-check
rm -rf install-dump
