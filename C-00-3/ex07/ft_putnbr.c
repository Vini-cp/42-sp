/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 05:05:03 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/26 19:07:03 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_pos(int nb)
{
	int		mult;
	int		nb_aux;
	char	c;

	nb_aux = nb;
	mult = 1;
	while (nb_aux > 9 && nb > 9)
	{
		nb /= 10;
		mult *= 10;
		if (nb < 10)
		{
			c = nb + 48;
			write(1, &c, 1);
			nb = nb_aux - nb * mult;
			nb_aux = nb;
			mult = 1;
		}
	}
	c = nb + 48;
	write(1, &c, 1);
}

void	print_neg(int nb)
{
	int		mult;
	int		nb_aux;
	char	c;

	nb++;
	nb *= -1;
	nb_aux = nb;
	mult = 1;
	while (nb_aux > 9 && nb > 9)
	{
		nb /= 10;
		mult *= 10;
		if (nb < 10)
		{
			c = nb + 48;
			nb = nb_aux - nb * mult;
			nb_aux = nb;
			write(1, &c, 1);
			mult = 1;
		}
	}
	c = nb + 49;
	write(1, &c, 1);
}

int		check_is_negative(int nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

void	ft_putnbr(int nb)
{
	int neg;

	neg = check_is_negative(nb);
	if (neg)
	{
		write(1, "-", 1);
		print_neg(nb);
	}
	else
		print_pos(nb);
}

int main ()
{
	ft_putnbr(-13540);
}