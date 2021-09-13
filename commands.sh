#!/bin/bash

# vogShip v1.2.1 Beta
#
# Author: Aaron Menadue (amenadue)
#         IsCoffeeTho#0001 (274012313785466881)

vogship() {
	flags=$(grep -o -E '(-\w+)' <<< $@)
	if [ -n "$flags" ]; then
		if grep -qoE '[v]' <<< $flags; then
			# Print Version
			echo -e "\e[92mVersion v1.2.1 \e[97m(\e[92mBeta\e[97m)\e[0m"
		else if grep -qoE '[u]' <<< $flags; then
			# Update VogShip
			if grep -qoE '[f]' <<< $flags; then
				curl -L -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/Installer.sh 2> ./install-dump
				chmod a+x Installer.sh
				./Installer.sh
			else
				curl -s -L -o vogship-version-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/version-check
				if grep -q 'vogShip v1.2.1 ' "vogship-version-check";
				then
					echo -e "\e[32mVogShip is already up to date!\e[0m"
					vogship -v
				else
					curl -L -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/Installer.sh 2> ./install-dump
					chmod a+x Installer.sh
					./Installer.sh
				fi
				rm vogship-version-check
			fi
		fi
	else
		echo -e "\e[94m     / /  |/| |\e[0m"
		echo -e "\e[94m   / /__.  / / \e[0m"
		echo -e "\e[94m /____  | | |/|  \e[104m|\e[49m  Vogship\e[0m"
		echo -e "\e[94m      | |\e[0m"
		echo ""
		echo -e "\e[92mMade by Developers for Developers\e[0m"
		echo ""
		echo -e "\e[96mWritten by Aaron Menadue"
		echo -e "\e[96mContributions from:"
		echo -e "\e[96m  Byron Hawksmith"
		echo -e "\e[96m  Tomas Turner"
	fi
}

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
	for f in $@;do
 		if ! grep -q 'By: * <*>' $f; then
			if ! grep -q 'Created: */*/* *:*:* by *' $f; then
				if ! grep -q 'Updated: */*/* *:*:* by *' $f; then
					vim -c 'Stdheader' -c 'wq' $f;
				fi
			fi
		fi
	done
}
