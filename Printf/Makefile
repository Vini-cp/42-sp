# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 23:08:03 by vcordeir          #+#    #+#              #
#    Updated: 2021/03/08 21:22:25 by vcordeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_LIST = ft_strtrim.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c \
ft_substr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_calloc.c ft_strlcpy.c \
ft_strlcat.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strmapi.c ft_strnstr.c \
ft_strdup.c ft_memcmp.c ft_memccpy.c ft_memdel.c ft_itoa.c ft_split.c ft_atoi.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
get_next_line.c \
ft_printf_putchar.c ft_printf_puthex.c ft_printf_putnbr.c ft_printf_putptr.c \
ft_printf_putstr.c ft_printf_putunbr.c ft_printf.c

SRCS = $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS = ${SRCS:.c=.o}

FOLDER = src

CFLAGS = -c -Wall -Werror -Wextra

RUNFLAGS = -Wall -Werror -Wextra

INCLUDE = -I./include

.PHONY: all clean fclean re

all:    $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

%.o: %.c
	@gcc ${CFLAGS} ${INCLUDE} -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:     fclean all

run:
	@gcc $(RUNFLAGS) ft_printf.c /Users/viniciuscp/Desktop/42-sp/Printf/$(NAME) \
	&& ./a.out \
	&& rm ./a.out

test:
	@gcc $(RUNFLAGS) test.c /Users/viniciuscp/Desktop/42-sp/Printf/$(NAME) \
	&& ./a.out \
	&& rm ./a.out