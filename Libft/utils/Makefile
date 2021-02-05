# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 22:40:41 by vcordeir          #+#    #+#              #
#    Updated: 2021/02/04 23:33:03 by vcordeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr.c ft_strlen.c \
ft_substr.c ft_tolower.c ft_toupper.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Werror -Wextra -I./ -c

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)

.PHONY: all clean fclean re

all:    $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
