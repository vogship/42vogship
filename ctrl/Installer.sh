#!/bin/bash
echo -e "\e[90mSearching for the Vogship...\e[0m"
curl -s -L -o vogship-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/version-check
if grep -q 'vogShip' 'vogship-check'; then
  curl -s -L -o vogship https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/src/commands.sh
  if grep -q ".*# vogShip .*" "vogship"; then
    echo -e "\e[90m---\[0m"
    if [ -f "~/.bashrc" ]; then
      echo -e "\e[97mCleaning Environment...\e[0m"
      rm -rf ~/.bashrc
    fi
    echo -e "Placing..."
    mv -f vogship ~/.bashrc
    echo -e "Verifying..."
    chmod a+x ~/.bashrc
    echo -e "Installing the Vogship..."
    source ~/.bashrc
    echo -e "Installation Complete."
  else
    mv vogShip install-dump
    rm vogship
    cp install-dump download-err.log
    echo -e "Created download-err.log file"
    echo -e "There is a problem trying to find vogShip"
  fi
else
  echo -e "\e[91mCannot connect to the Internet\e[0m"
fi
rm -rf vogship-check
rm -rf install-dump
rm -rf $0
