# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 23:08:03 by vcordeir          #+#    #+#              #
#    Updated: 2021/03/31 21:52:40 by vcordeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strtrim.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_abs.c \
ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c \
ft_substr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_calloc.c ft_strlcpy.c \
ft_strlcat.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strmapi.c ft_strnstr.c \
ft_strdup.c ft_memcmp.c ft_memccpy.c ft_memdel.c ft_split.c ft_atoi.c \
ft_itoa.c ft_utoa.c ft_ptoa.c ft_ctoa.c ft_strrev.c ft_max.c ft_min.c\
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_printf_putchar.c ft_printf.c ft_printf_print.c ft_printf_print_p_str.c \
ft_printf_print_c.c ft_printf_empty_zeros.c ft_printf_isflag.c \
ft_printf_get_flag.c ft_printf_newflag.c ft_isnegative.c\
get_next_line.c

OBJS = ${SRCS:.c=.o}

CFLAGS += -Wall -Werror -Wextra -I./ -c

all:    $(NAME)

$(NAME): $(OBJS)
	@gcc $(CFLAGS) $(SRCS)
	@ar -rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
