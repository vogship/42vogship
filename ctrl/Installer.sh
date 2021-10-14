#!/bin/bash
printf "Searching for the \e[92mVogship\e[0m...\n"
printf "check version: " > vogship.log
curl -s -L -o vogship-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/version-check > vogship.log 2> vogship.log
if grep -q 'vogShip' 'vogship-check'; then
	printf "Download vogship: " > vogship.log
	curl -s -L -o vogship https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/src/vogship.sh > vogship.log 2> vogship.log
	if grep -q ".*# vogShip .*" "vogship"; then
		if [ -f "~/.zshrc" ]; then
			printf "Petting Doggo..."
	  		if ! grep -qE "((source) (.*\.vogship\/vogship\.sh))" "~/.zshrc"; then
				echo "source ~/.vogship/vogship.sh" >> ~/.zshrc
	  		fi
		else
			echo "source ~/.vogship/vogship.sh" >> ~/.zshrc
		fi
		if [ -f "~/.bashrc" ]; then
			printf "Feeding the Dino..."
	  		if ! grep -qE "((source) (.*\.vogship\/vogship\.sh))" "~/.bashrc"; then
				echo "source ~/.vogship/vogship.sh" >> ~/.bashrc
	  		fi
		else
			echo "source ~/.vogship/vogship.sh" >> ~/.bashrc
		fi
		printf "Make .vogship foler: " > vogship.log
		mkdir ~/.vogship > vogship.log 2> vogship.log
		printf "Move downloaded vogship to .vogship foler: " > vogship.log
		mv -f vogship ~/.vogship/vogship.sh > vogship.log 2> vogship.log
		chmod a-w ~/.vogship/vogship.sh
		chmod a+rx ~/.vogship/vogship.sh
		source ~/.bashrc
		source ~/.zshrc
		source ~/.vogship/vogship.sh
		printf "\e[3m\e[97mAlmost\e[0m ready to lift off..."
		printf "Downloading Man Archive: " > vogship.log
		curl -s -L -o ~/.vogship/man.tar https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/src/man.tar > vogship.log 2> vogship.log
		printf "Decompress Man Archive: " > vogship.log
		tar -xf ~/.vogship/man.tar -C ~/.vogship/ > vogship.log 2> vogship.log
		rm -rf ~/.vogship/man.tar
		printf "Ready to \e[1m\e[92mFly\e[0m Through!"
		rm -rf ~/.vogship/latest-install.log
		mv vogship.log ~/.vogship/latest-install.log
	else
		rm vogship
		mv vogship.log download-err.log
		printf "Generated \e[91mvogship.log\e[0m"
		printf "There was a problem downloading VogShip, please check connection and try again."
	fi
else
	printf "\e[91mCannot connect to the Internet\e[0m"
fi
rm -rf vogship-check
rm -rf $0
