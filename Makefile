# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 23:46:33 by amenadue          #+#    #+#              #
#    Updated: 2022/02/23 14:40:23 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	This Makefile is self-destructive
#
#	After Installing vogship the directory will autoremove itself
#	

COMMANDS =	vogship \
			clsyc \
			genhead \
			rsthead \
			norm

CC =		gcc

CCFLAGS =	-Wall -Werror -Wextra

# OS Detection
ifeq ($(OS),Windows_NT)
    CCFLAGS += -D WIN32
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        CCFLAGS += -D AMD64
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            CCFLAGS += -D AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            CCFLAGS += -D IA32
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -D LINUX
    endif
    ifeq ($(UNAME_S),Darwin)
        CCFLAGS += -D OSX
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CCFLAGS += -D AMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        CCFLAGS += -D IA32
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CCFLAGS += -D ARM
    endif
endif

INCLDS = $(INCLUDES:%=includes/%)

all:
	-@printf "\e[31m   /\    \e[0m\n"
	-@printf "\e[31m  /__\   \e[0m\n"
	-@printf "\e[90m  |\e[0m42\e[90m|   \e[0mVogship\n"
	-@printf "\e[90m /|/\|\  \e[0m\e[s\n"
	-@printf "\e[90m/_||||_\ \e[0m\n"
	-@printf "\n\n\n"
	-@rm -rf ~/.vogship/* 2>/dev/null || true
	-@mkdir ~/.vogship 2>/dev/null || true
	-@mkdir ~/.vogship/bin 2>/dev/null || true
	-@mkdir ~/.vogship/man 2>/dev/null || true
	-@$(MAKE) all -s -C libvg 2>/dev/null || true
	-@cp libvg/libvg.a libvg.a 2>/dev/null || true
	-@printf "\e[uCompiling...\e[K\e[E\e[E   \e[31m()\e[0m\n\n"
	-@$(foreach COMMAND,$(COMMANDS), gcc cmds/$(COMMAND).c libvg.a -o ~/.vogship/bin/$(COMMAND);)
	-@printf "\e[uRegistering Commands...\e[K\e[E\e[E  \e[93m(\e[91m)(\e[93m)\e[0m\n   \e[93m||\e[0m\n"
	-@cp -r man ~/.vogship/man
	-@cp shell/vogship.sh ~/.vogship/vogship.sh
	-@$(if $(shell grep "source ~\/\.vogship\/vogship\.sh" ~/.bashrc),,@printf "source ~/.vogship/vogship.sh" >> ~/.bashrc)
	-@$(if $(shell grep "source ~\/\.vogship\/vogship\.sh" ~/.zshrc),,@printf "source ~/.vogship/vogship.sh" >> ~/.zshrc)
	-@$(source ~/.vogship/vogship.sh)
	-@printf "\e[uInstalled!\e[K\e[E\e[E  \e[93m|\e[91m)(\e[93m|\e[0m\n   \e[93m||\e[0m\n"

clean:
	-@$(MAKE) fclean -s -C libvg 2>/dev/null || true
	-@rm -rf libvg.a

.PHONY: clean
