#!/bin/zsh

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vogship.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 20:05:17 by amenadue          #+#    #+#              #
#    Updated: 2022/02/09 20:05:17 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VogShip v2
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
	gcc -Wall -Werror -Wextra $@ -o a
	./a
	rm a
}

norm() {
	if [ -z "$1" ]; then
		norm * 
	else
		~/.vogship/bin/norm $@
	fi
}

medir() {
	mkdir $1
	cd $1
}