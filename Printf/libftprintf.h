/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:14:56 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/04 21:05:29 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_put_unsignednbr(unsigned int n);
void	ft_puthex(unsigned int n, int bool_lower);
void	ft_putpointer(uintptr_t n);

#endif
