/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 02:59:42 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/30 20:47:46 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rev_array(char *str);
int		check_neg(int nb);
void	nb_to_char(char *str, unsigned int nb, int neg);

void	ft_putnbr(int nb)
{
	char			str[12];
	int				neg;
	int				i;
	unsigned int	n;

	neg = check_neg(nb);
	i = 0;
	if (neg)
		n = nb * (-1);
	else
		n = nb;
	if (nb == 0)
		ft_putchar('0');
	else
	{
		nb_to_char(str, n, neg);
		rev_array(str);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
