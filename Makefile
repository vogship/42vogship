# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 23:46:33 by amenadue          #+#    #+#              #
#    Updated: 2022/04/05 19:12:58 by amenadue         ###   ########.fr        #
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
	-@make rocket1 -s
	-@printf "\n"
	-@make rocket2 -s
	-@printf "\n\n\n"
	-@rm -rf ~/.vogship 2>/dev/null || true
	-@mkdir ~/.vogship 2>/dev/null || true
	-@mkdir ~/.vogship/bin 2>/dev/null || true
	-@$(MAKE) all -s -C libft 2>/dev/null || true
	-@cp libft/libft.a libft.a 2>/dev/null || true
	-@$(MAKE) all -s -C libpm 2>/dev/null || true
	-@cp libpm/libpm.a libpm.a 2>/dev/null || true
	-@$(MAKE) all -s -C libvg 2>/dev/null || true
	-@cp libvg/libvg.a libvg.a 2>/dev/null || true
	-@make rocket1 -s
	-@printf "Compiling...\n"
	-@make rocket2 -s
	-@printf "   \e[31m()\e[0m\n\n"
	-@$(foreach COMMAND,$(COMMANDS), gcc cmds/$(COMMAND).c libvg.a libft.a -o ~/.vogship/bin/$(COMMAND) 2>/dev/null || true;)
	-@make rocket1 -s
	-@printf "Registering Commands...\n"
	-@make rocket2 -s
	-@printf "  \e[93m(\e[91m)(\e[93m)\e[0m\n   \e[93m||\e[0m\n"
	-@cp -r man ~/.vogship/
	-@cp shell/vogship.sh ~/.vogship/vogship.sh
	-@$(if $(shell grep "source ~\/\.vogship\/vogship\.sh" ~/.bashrc),,@printf "source ~/.vogship/vogship.sh" >> ~/.bashrc)
	-@$(if $(shell grep "source ~\/\.vogship\/vogship\.sh" ~/.zshrc),,@printf "source ~/.vogship/vogship.sh" >> ~/.zshrc)
	-@$(source ~/.vogship/vogship.sh)
	-@make rocket1 -s
	-@printf "Installed!\n"
	-@make rocket2 -s
	-@printf "  \e[93m|\e[91m)(\e[93m|\e[0m\n   \e[93m||\e[0m\n"

verbose:
	rm -rf ~/.vogship
	mkdir ~/.vogship
	mkdir ~/.vogship/bin
	$(MAKE) verbose -C libft
	cp libft/libft.a libft.a
	$(MAKE) verbose -C libvg
	cp libvg/libvg.a libvg.a
	$(foreach COMMAND,$(COMMANDS), gcc cmds/$(COMMAND).c libvg.a libft.a -g3 -o ~/.vogship/bin/$(COMMAND);)
	cp -r man ~/.vogship/
	cp shell/vogship.sh ~/.vogship/vogship.sh
	$(if $(shell grep "source ~\/\.vogship\/vogship\.sh" ~/.bashrc),,printf "source ~/.vogship/vogship.sh" >> ~/.bashrc)
	$(if $(shell grep "source ~\/\.vogship\/vogship\.sh" ~/.zshrc),,printf "source ~/.vogship/vogship.sh" >> ~/.zshrc)
	$(source ~/.vogship/vogship.sh)

v: verbose

rocket1:
	-@clear
	-@printf "\e[31m   /\    \e[0m\n"
	-@printf "\e[31m  /__\   \e[0m\n"
	-@printf "\e[90m  |\e[0m42\e[90m|   \e[0mVogship\n"
	-@printf "\e[90m /|/\|\  \e[0m"

rocket2:
	-@printf "\e[90m/_||||_\ \e[0m\n"

clean:
	-@$(MAKE) clean -s -C libft 2>/dev/null || true
	-@rm -rf libft.a
	-@$(MAKE) clean -s -C libvg 2>/dev/null || true
	-@rm -rf libvg.a

fclean: clean
	-@$(MAKE) fclean -s -C libft 2>/dev/null || true
	-@$(MAKE) fclean -s -C libvg 2>/dev/null || true

.PHONY: clean
