#!/bin/bash
echo -e "Searching for the Vogship..."
curl -s -L -o vogship-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/version-check
if grep -q 'vogShip' 'vogship-check'; then
  curl -s -L -o vogship https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/src/vogship.sh
  if grep -q ".*# vogShip .*" "vogship"; then
    echo -e "---"
    if [ -f "~/.bashrc" ]; then
      echo -e "Cleaning Environment..."
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
  echo -e "Cannot connect to the Internet"
fi
rm -rf vogship-check
rm -rf install-dump
rm -rf $0
