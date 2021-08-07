#!/bin/zsh

# vogShip v1 Beta
# 
# Author: Aaron Menadue    (amenadue)
#         IsCoffeeTho#0001 (274012313785466881)

compile() {
  zsh
  gcc -Wall -Werror -Wextra $@
}

car() {
  zsh
  gcc -Wall -Werror -Wextra $@ -o a
  ./a
  rm a
}

norm() {
  zsh
  Norminette -R CheckForbiddenSourceHeader $@
}

medir() {
  zsh
  mkdir $1
  cd $1
}

cls() {
  zsh
  clear
}

genmain() {
  zsh
  echo -e "\e[91Command not Supported"
}

updateVogship() {
  zsh
  curl -s -L --trace-ascii install-dump -o vogship-version-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/version-check
  if grep -q 'vogShip v1 ' "vogship-version-check";
  then
    if $1 = '-f';
    then
      curl -s -L --trace-ascii install-dump -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/Installer.sh
      ./Installer.sh
    else 
      echo -e '\e[32mVogShip is already up to date!'
      echo -e '\e[92mVersion v1 \e[97m(\e[92mBeta\e[97m)\e[0m'
    fi
  else 
    curl -s -L --trace-ascii install-dump -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/Installer.sh
    ./Installer.sh
  fi
}