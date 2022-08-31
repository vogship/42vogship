# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 23:46:33 by amenadue          #+#    #+#              #
#    Updated: 2022/08/31 21:18:55 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMMANDS =	vogship \
			clsyc \
			genhead \
			rsthead \
			norm 

CC =		gcc

CCFLAGS =	-Wall -Werror -Wextra

# OS Detection
ifeq ($(OS),Windows_NT)
    CCFLAGS += -DWIN32
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        CCFLAGS += -DAMD64
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            CCFLAGS += -DAMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            CCFLAGS += -DIA32
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -DLINUX
    endif
    ifeq ($(UNAME_S),Darwin)
        CCFLAGS += -DOSX
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CCFLAGS += -DAMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        CCFLAGS += -DIA32
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CCFLAGS += -DARM
    endif
endif

INCLDS = $(INCLUDES:%=includes/%)

all:
	@$(MAKE) -s rocket1
	@printf "\n"
	@$(MAKE) -s rocket2
	@printf "\n\n\n"
	@rm -rf ~/.vogship || $(MAKE) -s error
	@mkdir ~/.vogship || $(MAKE) -s error
	@mkdir ~/.vogship/bin || $(MAKE) -s error
	@$(MAKE) all -s -C libft || $(MAKE) -s error
	@$(MAKE) all -s -C libvg || $(MAKE) -s error
	@$(MAKE) -s rocket1
	@printf "Compiling...\n"
	@$(MAKE) -s rocket2
	@printf "   \e[31m()\e[0m\n\n"
	@$(foreach COMMAND,$(COMMANDS), gcc $(CCFLAGS) cmds/$(COMMAND).c -Llibvg -lvg -Llibft -lft -o ~/.vogship/bin/$(COMMAND) || $(MAKE) -s error;)
	@$(MAKE) -s rocket1
	@printf "Registering Commands...\n"
	@$(MAKE) -s rocket2
	@printf "  \e[93m(\e[91m)(\e[93m)\e[0m\n   \e[93m||\e[0m\n"
	@cp -r man ~/.vogship/ || $(MAKE) -s error
	@cp shell/vogship.sh ~/.vogship/vogship.sh || $(MAKE) -s error
	@$(if $(shell grep "source ~\/\.vogship\/vogship\.sh" ~/.bashrc),,@printf "source ~/.vogship/vogship.sh" >> ~/.bashrc)
	@$(if $(shell grep "source ~\/\.vogship\/vogship\.sh" ~/.zshrc),,@printf "source ~/.vogship/vogship.sh" >> ~/.zshrc)
	@$(source ~/.vogship/vogship.sh)
	@$(MAKE) -s rocket1
	@printf "Installed!\n"
	@$(MAKE) -s rocket2
	@printf "  \e[93m|\e[91m)(\e[93m|\e[0m\n   \e[93m||\e[0m\n"

verbose:
	-rm -rf ~/.vogship
	mkdir ~/.vogship  || $(MAKE) -s error
	mkdir ~/.vogship/bin  || $(MAKE) -s error
	$(MAKE) verbose -C libft || $(MAKE) -s error
	$(MAKE) verbose -C libvg || $(MAKE) -s error
	$(foreach COMMAND,$(COMMANDS), gcc $(CCFLAGS) cmds/$(COMMAND).c -Llibvg -lvg -Llibft -lft -g3 -o ~/.vogship/bin/$(COMMAND) || $(MAKE) -s error;) 
	cp -r man ~/.vogship/ || $(MAKE) error
	cp shell/vogship.sh ~/.vogship/vogship.sh || $(MAKE) error
	$(if $(shell grep "source ~\/\.vogship\/vogship\.sh" ~/.bashrc),,printf "source ~/.vogship/vogship.sh" >> ~/.bashrc)
	$(if $(shell grep "source ~\/\.vogship\/vogship\.sh" ~/.zshrc),,printf "source ~/.vogship/vogship.sh" >> ~/.zshrc)
	$(source ~/.vogship/vogship.sh)

v: verbose

rocket1:
	@clear
	@printf "\e[1m\e[31m   /\    \e[0m\n"
	@printf "\e[1m\e[31m  /__\   \e[0m\n"
	@printf "\e[1m\e[90m  |\e[0m\e[97m42\e[1m\e[90m|   \e[0mVogship\n"
	@printf "\e[1m\e[90m /|/\|\  \e[0m"

rocket2:
	@printf "\e[1m\e[90m/_||||_\ \e[0m\n"

clean:
	@$(MAKE) clean -s -C libft || $(MAKE) -s error
	@rm -rf libft.a
	@$(MAKE) clean -s -C libvg || $(MAKE) -s error
	@rm -rf libvg.a

fclean: clean
	@$(MAKE) fclean -s -C libft || $(MAKE) -s error
	@$(MAKE) fclean -s -C libvg || $(MAKE) -s error

error:
	@printf "This was not meant to happen\n"
	@printf "You can report this to https://github.com/vogship/42vogship/issues\n"
	@exit 1

.PHONY: clean
