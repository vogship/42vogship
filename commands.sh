# vogShip v1 Beta
# 
# Author: Aaron Menadue (amenadue)
#         IsCoffeeTho#0001 (274012313785466881)
#

compile() {
  gcc -Wall -Werror -Wextra $@
  echo -e "\e[36m"
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

update-vogship() {
  curl -s -L -o vogship-version-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/version-check
  if grep -q 'vogShip v1' "vogship-version-check";
  then
    echo -e "\e[32mVogShip is already up to date!"
    echo -e "\e[92mVersion v1 \e[97m(\e[92mBeta\e[97m)\e[0m"
  else 
    curl -L -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/Installer.sh 2> ./install-dump
    ./Installer.sh
  fi
}

cls() {
  clear
}