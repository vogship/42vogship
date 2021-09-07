#!/bin/bash

# vogShip v1.1 Beta
#
# Author: Aaron Menadue (amenadue)
#         IsCoffeeTho#0001 (274012313785466881)

compile() {
  gcc -Wall -Werror -Wextra $@
}

car() {
  gcc -Wall -Werror -Wextra $@ -o a
  ./a
  rm a
}

norm() {
  Norminette -R CheckForbiddenSourceHeader $@
}

medir() {
  mkdir $1
  cd $1
}

cls() {
  clear
}

genhead() {
  for f in $@;
  do
    if ! grep -q 'By: * <*@*>' $f; then
      if ! grep -q 'Created: */*/* *:*:* by *' $f; then
        if ! grep -q 'Updated: */*/* *:*:* by *' $f; then
          vim -c 'Stdheader' -c 'wq' $f;
        fi
      fi
    fi
  done
}

updateVogship() {
  curl -s -L -o vogship-version-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/version-check
  if grep -q 'vogShip v1.1 ' "vogship-version-check";
  then
    if $1 = '-f';
    then
      curl -L -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/Installer.sh 2> ./install-dump
      chmod a+x Installer.sh
      ./Installer.sh
    else
      echo -e '\e[32mVogShip is already up to date!'
      echo -e '\e[92mVersion v1.1 \e[97m(\e[92mBeta\e[97m)\e[0m'
    fi
  else
    curl -L -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/Installer.sh 2> ./install-dump
    chmod a+x Installer.sh
    ./Installer.sh
  fi
}
