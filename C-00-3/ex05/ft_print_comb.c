/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:45:43 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/22 20:56:28 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	define_carray(char *c, int i)
{
	c[2] = (i % 10) + 48;
	c[1] = ((i - i % 10) / 10 % 10) + 48;
	c[0] = ((i - i % 100) / 100) + 48;
}

void	ft_print_comb(void)
{
	char	c[3];
	int		i;
	int		first;

	first = 1;
	i = 0;
	while (i <= 789)
	{
		define_carray(c, i);
		if (c[0] < c[1] && c[1] < c[2] && first)
		{
			write(1, &c, 3);
			first = 0;
		}
		else if (c[0] < c[1] && c[1] < c[2])
		{
			write(1, ", ", 2);
			write(1, &c, 3);
		}
		i++;
	}
}
