# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 23:34:30 by vcordeir          #+#    #+#              #
#    Updated: 2021/03/02 00:20:32 by vcordeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Werror -Wextra -I./ -c

RUNFLAGS += -Wall -Werror -Wextra

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)

.PHONY: all clean fclean re lib run test utils

all:    $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re:     fclean all

run:
	@gcc -g3 -fsanitize=address -Wall -Wextra -Werror -D BUFFER_SIZE=$(BF) \
    get_next_line.c get_next_line_utils.c && \
    valgrind --leak-check=full --show-leak-kinds=all -s ./a.out \
    && rm ./a.out
	
test:
	@gcc -Wall -Wextra -Werror test.c && ./a.out && rm ./a.out

utils:
	@gcc -Wall -Wextra -Werror get_next_line_utils.c && ./a.out && rm ./a.out