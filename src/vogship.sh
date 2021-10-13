#!/bin/zsh

# vogShip v1.2.3 Beta
#
# Author: Aaron Menadue (amenadue)
#         IsCoffeeTho#0001 (274012313785466881)

alias man='man -M ~/.vogship/man:$(manpath)'

vogship() {
    flags=$(grep -o -E '(-\w+)' <<< $@)
    if [ -n "$flags" ]; then
        if grep -qoE '[v]' <<< $flags; then
            # Print Version
            printf "\e[92mVersion v1.2.4 \e[97m(\e[92mBeta\e[97m)\e[0m\n"
            printf "\e[90mPatchVer660192\e[0m\n"
        elif grep -qoE '[h]' <<< $flags; then
            printf "\e[92mCommands Available:\e[0m\n"
            printf "    \e[96m\e[48;5;235m car \e[94m<files> \e[0m Compiles, Runs, and Returns.\n"
            printf "    \e[96m\e[48;5;235m clsyc \e[94m<flags> \e[0m Clears up memory leaks to free up space.\n"
			printf "    \e[96m\e[48;5;235m cls \e[0m Clears the screen.\n"
            printf "    \e[96m\e[48;5;235m compile \e[94m[<gcc parameters>] <files> \e[0m Compiles anything with \e[97m-Wall -Wextra -Werror\e[0m.\n"
            printf "    \e[96m\e[48;5;235m genhead \e[94m<files> \e[0m Puts the \e[97m:Stdheader\e[0m in the specified files without duplicates.\n"
            printf "    \e[96m\e[48;5;235m medir \e[94m<name> \e[0m Create and Enter a directory.\n"
            printf "    \e[96m\e[48;5;235m norm \e[94m<files> \e[0m Runs Norminette on each file with the correct flags for both \e[96m.c\e[0m and \e[96m.o\e[0m files.\n"
            printf "    \e[96m\e[48;5;235m vogship \e[94m<flags> \e[0m The Vogship command helping you soar through 42 Shell.\n"
        elif grep -qoE '[u]' <<< $flags; then
            # Update VogShip
            if grep -qoE '[f]' <<< $flags; then
                curl -L -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/Installer.sh 2> ./install-dump
                chmod a+x Installer.sh
                ./Installer.sh
            else
                curl -s -L -o vogship-version-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/version-check
                if grep -q "vogShip v1.2.4 (BETA) pV 660192" "vogship-version-check"; then
                    printf "\e[32mVogShip is already up to date!\e[0m\n"
                    rm -rf vogship-version-check
					vogship -v
                else
                    rm -rf vogship-version-check
					curl -L -o Installer.sh https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/Installer.sh 2> ./install-dump
                    chmod a+x Installer.sh
                    ./Installer.sh
                fi
			fi
        fi
    else
		printf "\n\e[94m     / /  |/| |\e[0m\n"
        printf "\e[94m   / /__   / / \e[0m\n"
        printf "\e[94m /____  | | |/|  █  Vogship\e[0m\n"
        printf "\e[94m      | |\e[0m\n\n"
        printf "\e[92mMade by Developers for Developers\e[0m\n\n"
        printf "\e[96mWritten by Aaron Menadue\n"
        printf "\e[96mContributions from:\n"
        printf "\e[96m  Byron Hawksmith\n"
		printf "\e[96m  Jaymie Gobbett\n"
        printf "\e[96m  Pasquale Rossi\n"
		printf "\e[96m  Tomas Turner\e[0m\n"
    fi
}

clsyc() {
	printf "\e[92mBefore Cleanup: "
	grep -oE "\d+" <<< $(grep -E "/Users/\w+$" <<< $(du -Hk ~ 2> /dev/null))
	for dir in ~/Library/Caches/*; do
		rm -rf $dir
	done
	echo -en "\e[92mAfter Cleanup: "
	grep -oE "\d+" <<< $(grep -E "/Users/\w+$" <<< $(du -Hk ~ 2> /dev/null))
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
			if ! grep -qE "\w+((\.a)|(\.o))" <<< $f; then
				if ! grep -qE "(By: .* <.*>)" $f; then
					if ! grep -qE "(Created: .*/.*/.* .*:.*:.* by .*)" $f; then
						if ! grep -qE "(Updated: .*/.*/.* .*:.*:.* by .*)" $f; then
							vim -c 'Stdheader' -c 'wq' $f;
						fi
					fi
				fi
			fi
		done
	fi
}
