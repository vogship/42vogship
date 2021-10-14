#!/bin/bash
echo -e "Searching for the Vogship..."
curl -s -L -o vogship-check https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/ctrl/version-check
if grep -q 'vogShip' 'vogship-check'; then
	curl -s -L -o vogship https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/src/vogship.sh
	if grep -q ".*# vogShip .*" "vogship"; then
		echo -e "---"
		if [ -f "~/.zshrc" ]; then
			echo -e "Petting Doggo..."
	  		if ! grep -qE "((source) (.*\.vogship\/vogship\.sh))" "~/.zshrc"; then
				echo "source ~/.vogship/vogship.sh" >> ~/.zshrc
	  		fi
		else
			echo "source ~/.vogship/vogship.sh" >> ~/.zshrc
		fi
		if [ -f "~/.bashrc" ]; then
			echo -e "Feeding the Dino..."
	  		if ! grep -qE "((source) (.*\.vogship\/vogship\.sh))" "~/.bashrc"; then
				echo "source ~/.vogship/vogship.sh" >> ~/.bashrc
	  		fi
		else
			echo "source ~/.vogship/vogship.sh" >> ~/.bashrc
		fi
		mkdir ~/.vogship > /dev/null 2> /dev/null
		mv -f vogship ~/.vogship/vogship.sh
		chmod a-w ~/.vogship/vogship.sh
		chmod a+rx ~/.vogship/vogship.sh
		source ~/.bashrc
		source ~/.zshrc
		source ~/.vogship/vogship.sh
		echo "Vogship is almost ready to lift off."
		echo "Installing man pages."
		curl -s -L -o ~/.vogship/man.tar https://raw.githubusercontent.com/IsCoffeeTho/42vogship/master/src/man.tar
		tar -xf ~/.vogship/man.tar -C ~/.vogship/
		rm -rf ~/.vogship/man.tar
		echo "Installation Complete."
	else
		mv vogship install-dump 2> /dev/null
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
