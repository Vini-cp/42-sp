/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:43:04 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/25 04:09:08 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	define_carray(char *c, int i, int j)
{
	c[2] = 32;
	c[1] = (i % 10) + 48;
	c[0] = ((i - i % 10) / 10 % 10) + 48;
	c[4] = (j % 10) + 48;
	c[3] = ((j - j % 10) / 10 % 10) + 48;
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	c[5];

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			define_carray(c, i, j);
			if (i >= 0 && j > 1)
			{
				write(1, ", ", 2);
			}
			write(1, &c, 5);
			j++;
		}
		i++;
	}
}
