# ============================================================================ #
#                                                                              #
#                                                               /   /   \      #
#   Made By IsCoffeeTho (Aaron Menadue)                       /    |      \    #
#                                                            |     |       |   #
#   vogship.sh                                               |      \      |   #
#                                                            |       |     |   #
#   Last Edited: 08:25AM 17/08/2023                           \      |    /    #
#                                                               \   /   /      #
#                                                                              #
# ============================================================================ #

# VogShip v2.1.1
#
# Author:	Aaron Menadue (amenadue)
# DISCORD:	IsCoffeeTho#0001 (274012313785466881)

# Command forwarding

alias man='man -M ~/.vogship/man:$(manpath)'
git config --global alias.reverse 'reset --hard HEAD'

alias vogship="~/.vogship/bin/vogship"
alias compile="gcc -Wall -Werror -Wextra"
alias clsyc="~/.vogship/bin/clsyc"
alias cls="clear"
alias genhead="~/.vogship/bin/genhead"
alias rsthead="~/.vogship/bin/rsthead"

car() {
	gcc -Wall -Werror -Wextra $@ -o /tmp/compiled_bin
	/tmp/compiled_bin
	rm -f /tmp/compiled_bin
}

norm() {
	if [ -z "$1" ]; then
		norm .
	else
		~/.vogship/bin/norm $@
	fi
}

medir() {
	mkdir $1
	cd $1
}