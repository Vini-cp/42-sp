/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:55:05 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 17:23:06 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	rev_array(char *str);
static	int		check_neg(int nb);
static	void	nb_to_char(char *str, unsigned int nb, int neg);

void	ft_putnbr_fd(int n, int fd)
{
	char			str[12];
	int				neg;
	int				i;
	unsigned int	nb;

	neg = check_neg(n);
	i = 0;
	if (neg)
		nb = n * (-1);
	else
		nb = n;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		nb_to_char(str, nb, neg);
		rev_array(str);
	}
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

void	rev_array(char *str)
{
	int		len;
	int		i;
	char	c;

	len = 0;
	i = 0;
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
}

int		check_neg(int nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

void	nb_to_char(char *str, unsigned int nb, int neg)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	str[i] = (nb % 10) + '0';
	if (neg)
	{
		str[i] = '-';
		str[i + 1] = '\0';
	}
	else
		str[i] = '\0';
}
