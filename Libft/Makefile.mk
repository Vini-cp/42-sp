# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 23:34:30 by vcordeir          #+#    #+#              #
#    Updated: 2021/02/11 15:28:06 by vcordeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c \
ft_substr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_calloc.c ft_strlcpy.c \
ft_strlcat.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strmapi.c ft_strnstr.c \
ft_strdup.c ft_memcmp.c ft_memccpy.c ft_itoa.c ft_split.c ft_strtrim.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS += -Wall -Werror -Wextra -I./ -c

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)

.PHONY: all clean fclean re

all:    $(NAME)

bonus:
	gcc $(CFLAGS) $(SRC_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re:     fclean all
