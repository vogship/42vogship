# ============================================================================ #
#                                                                              #
#                                                               /   /   \      #
#   Made By IsCoffeeTho (Aaron Menadue)                       /    |      \    #
#                                                            |     |       |   #
#   Makefile                                                 |      \      |   #
#                                                            |       |     |   #
#   Last Edited: 08:29AM 17/08/2023                           \      |    /    #
#                                                               \   /   /      #
#                                                                              #
# ============================================================================ #

# Config

NAME	=	libft

SRC 	=	ft_strlen.c \
			ft_memmove.c \
			ft_memcpy.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memset.c \
			ft_bzero.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c	\
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_printf.c \
			ft_internal_print_a.c \
			ft_internal_print_b.c \
			ft_gnl.c

# EnvVars (Do not touch unless you understand and know what is happening, which you probably do)

CC		=	gcc

CCFLAGS	=	-Wall -Wextra -Werror

OBJS	= $(SRC:%.c=%.o)

$(NAME).a:
	-@$(CC) $(CCFLAGS) -c $(SRC) -I./
	-@ar -rc $(NAME).a $(OBJS)
	-@printf "made libft.a\n"

all: $(NAME).a

clean:
	-@rm -f $(OBJS)

fclean: clean
	-@rm -f $(NAME).a

re: fclean all

verbose: re

.PHONY: all, clean, fclean, re
