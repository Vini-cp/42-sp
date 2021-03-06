/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:14:56 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/06 16:25:55 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
#include <stdio.h>

int	ft_printf(const char *fmt, ...);
int	ft_strlen(const char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned int n, int bool_lower);
int	ft_putptr(uintptr_t n);

#endif
