/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:49:53 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/30 21:25:16 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		verify(char *base);
void	rev_array(char *str);
int		check_neg(int nb);
void	nb_to_char(char *str, unsigned int nb, int neg, int size);

void	ft_putnbr_base(int nbr, char *base)
{
	char			str[100];
	int				neg;
	int				i;
	int				size;
	unsigned int	n;

	if (verify(base))
	{
		neg = check_neg(nbr);
		size = 0;
		while (base[size] != '\0')
			size++;
		if (neg)
			n = nbr * (-1);
		else
			n = nbr;
		nb_to_char(str, n, neg, size);
		rev_array(str);
		i = 0;
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

int		verify(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j] != '\0' && i != j)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	else
		return (1);
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

void	nb_to_char(char *str, unsigned int nb, int neg, int size)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		if ((nb % size) > 9)
			str[i] = (nb % size) - 10 + 'A';
		else
			str[i] = (nb % size) + '0';
		nb /= size;
		i++;
	}
	if ((nb % size) > 9)
		str[i] = (nb % size) - 10 + 'A';
	else
		str[i] = (nb % size) + '0';
	if (neg)
	{
		str[i] = '-';
		str[i + 1] = '\0';
	}
	else
		str[i] = '\0';
}
