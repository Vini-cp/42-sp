/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:23:20 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/26 17:29:36 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		define_lim(int n);
int		define_init(int n);
int		mount_check_char(char *c, int n, int i);

void	ft_print_combn(int n)
{
	char	c[n];
	int		i;
	int		lim;
	int		first;

	first = 1;
	lim = define_lim(n);
	i = define_init(n);
	while (i <= lim)
	{
		if (mount_check_char(c, n, i))
		{
			if (!first)
			{
				write(1, ", ", 2);
			}
			write(1, &c, n);
			first = 0;
		}
		i++;
	}
}

int		define_lim(int n)
{
	int lim;
	int aux;
	int pot;

	lim = 0;
	pot = 1;
	aux = 9;
	while (n > 0)
	{
		lim += pot * aux;
		n -= 1;
		aux -= 1;
		pot *= 10;
	}
	return (lim);
}

int		define_init(int n)
{
	int lim;
	int aux;
	int pot;

	lim = n;
	pot = 1;
	while (lim > 2)
	{
		pot *= 10;
		lim--;
	}
	lim = 0;
	aux = 1;
	while (n > 1)
	{
		lim += pot * aux;
		n--;
		aux++;
		pot /= 10;
	}
	return (lim);
}

int		mount_check_char(char *c, int n, int i)
{
	int aux;

	aux = n;
	while (i != 0)
	{
		c[n - 1] = (i % 10) + 48;
		i = (i - (i % 10)) / 10;
		if (aux != n)
		{
			if (c[n - 1] >= c[n])
				return (0);
		}
		n--;
	}
	while (n > 0)
	{
		c[n - 1] = 48;
		n -= 1;
	}
	return (1);
}

int main()
{
	ft_print_combn(8);
}