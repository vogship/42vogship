# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 23:46:33 by amenadue          #+#    #+#              #
#    Updated: 2022/02/26 10:48:40 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvg

FILES =	vg_info.c \
		vg_util.c \
		vg_util1.c \
		vg_cmds.c

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

OBJS = $(FILES:.c=.o)

all: fclean
	-@gcc -c $(FILES)
	-@ar -rcs $(NAME).a $(OBJS)

clean:
	-@rm -rf $(NAME).a

fclean: clean
	-@rm -rf $(OBJS)