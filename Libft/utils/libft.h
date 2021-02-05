/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:49:20 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/05 00:26:55 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H_
#define LIBFT_H_

#include <string.h>

int		ft_atoi(const char *str);
void    ft_bzero(void *s, size_t n);
int     ft_isalnum(int c);
int 	ft_isalpha(int c);
int     isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void    *ft_memchr(const void *s, int c, unsigned int n);
int     ft_memcmp(const void *s1, const void *s2, unsigned int n);
void    *ft_memcpy(void *dest, const void *src, unsigned int n);
void    *ft_memmove(void *dest, const void *src, unsigned int n);
void    *ft_memset(void *s, int c, unsigned int n);
void	ft_putchar(char c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int     ft_tolower(int c);
int		ft_toupper(int c);

#endif
