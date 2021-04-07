# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 23:08:03 by vcordeir          #+#    #+#              #
#    Updated: 2021/04/03 11:04:13 by vcordeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub.a

SRCS_LIST = main.c draw.c update.c setup.c key_touch.c has_wall.c end_game.c

FOLDER = src

SRCS = $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra
# -g -fsanitize=address

LINUX_FLAGS = -lXext -lX11 -lm -lmlx -Lmlx -lbsd -L/usr/lib

INCLUDE = -I./include

all : $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@cp libft/libft.a $(NAME)
	@clang  $(SRCS) $(CFLAGS) $(INCLUDES) $(LINUX_FLAGS) cub.a -o cub3D
	@ar -rcs $(NAME) $(OBJS)

clean :
	@$(MAKE) clean -C ./libft
	@rm -rf *.o
	@rm -rf ./src/*.o
	@rm -f cub

fclean : clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

re : fclean all

cub:
	@gcc src/main.c -Lmlx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm cub.a -o cub

ccub:
	@rm cub

.PHONY: all clean fclean re
