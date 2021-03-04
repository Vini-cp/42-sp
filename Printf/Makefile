# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 23:08:03 by vcordeir          #+#    #+#              #
#    Updated: 2021/03/04 10:21:35 by vcordeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = *.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Werror -Wextra -I./ -c

.PHONY: all clean fclean re

all:    $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re:     fclean all
