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

vogship() {
	~/.vogship/bin/vogship $@ 
}

clsyc() {
	~/.vogship/bin/clsyc
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
		~/.vogship/bin/norm $@
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
	~/.vogship/bin/genhead $@
}

rsthead() {
	~/.vogship/bin/rsthead $@
}