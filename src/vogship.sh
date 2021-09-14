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
            echo -e "\e[40mPatchVer1132"
        elif grep -qoE '[h]' <<< $flags; then
            echo -e "\e[92mCommands Available:\e[0m"
            echo -e "    \e[96m\e[48;5;235m car \e[94m<files> \e[0m Compiles, Runs, and Returns."
            echo -e "    \e[96m\e[48;5;235m cls \e[0m Clears the screen."
            echo -e "    \e[96m\e[48;5;235m compile  \e[94mp[<gcc parameters>] <files> \e[0m Compiles anything with \e[97m-Wall -Wextra -Werror\e[0m."
            echo -e "    \e[96m\e[48;5;235m genhead \e[94m<files> \e[0m Puts the \e[97m:Stdheader\e[0m in the specified files without duplicates."
            echo -e "    \e[96m\e[48;5;235m medir \e[94m<name> \e[0m Create and Enter a directory."
            echo -e "    \e[96m\e[48;5;235m norm \e[94m<files> \e[0m Runs Norminette on each file with the correct flags for both \e[96m.c\e[0m and \e[96m.o\e[0m files."
            echo -e "    \e[96m\e[48;5;235m vogship \e[94m<flags> \e[0m The Vogship command helping you soar through 42 Shell."
        elif grep -qoE '[u]' <<< $flags; then
            # Update VogShip
            if grep -qoE '[f]' <<< $flags; then
                curl -L -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/Installer.sh 2> ./install-dump
                chmod a+x Installer.sh
                ./Installer.sh
            else
                curl -s -L -o vogship-version-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/version-check
                if grep -q "vogShip v1.2.1 (BETA) Patch1132" "vogship-version-check"; then
                    echo -e "\e[32mVogShip is already up to date!\e[0m"
                    vogship -v
                else
                    curl -L -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/Installer.sh 2> ./install-dump
                    chmod a+x Installer.sh
                    ./Installer.sh
                fi
                rm -rf vogship-version-check.ver
                fi
        fi
    else
        echo -e "\e[94m     / /  |/| |\e[0m"
        echo -e "\e[94m   / /__.  / / \e[0m"
        echo -e "\e[94m /____  | | |/|  █  Vogship\e[0m"
        echo -e "\e[94m      | |\e[0m"
        echo ""
        echo -e "\e[92mMade by Developers for Developers\e[0m"
        echo ""
        echo -e "\e[96mWritten by Aaron Menadue"
        echo -e "\e[96mContributions from:"
        echo -e "\e[96m  Byron Hawksmith"
	echo -e "\e[96m  Jaymie Gobbett"
        echo -e "\e[96m  Pasquale Rossi"
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
	if [ -z "$1" ]; then
		norm * 
	else
		for f in $@; do
			if grep -qoE '(.*\.c)' <<< $f; then
				Norminette -R CheckForbiddenSourceHeader $f
			fi
			if grep -qoE '(.*\.h)' <<< $f; then
				Norminette -R CheckDefine $f
			fi
		done
	fi
}

medir() {
	mkdir $1
	cd $1
}

cls() {
	clear
}

genhead() {
	if [ -z "$1" ]; then
		genhead *
	else
		for f in $@; do
			if ! grep -Eq "(By: .* <.*>)" $f; then
				if ! grep -Eq "(Created: .*/.*/.* .*:.*:.* by .*)" $f; then
					if ! grep -Eq "(Updated: .*/.*/.* .*:.*:.* by .*)" $f; then
						vim -c 'Stdheader' -c 'wq' $f;
					fi
				fi
			fi
		done
	fi
}
