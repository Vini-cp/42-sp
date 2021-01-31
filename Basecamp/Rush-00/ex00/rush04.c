/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:18:26 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/23 00:09:52 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	first_last_column(int i, int j, int x, int y);
void	middle_column(int j, int y);

void	rush(int x, int y)
{
	int i;
	int j;

	if (x * y <= 0)
	{
		x = 0;
		y = 0;
	}
	i = 0;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (i == 0 || i == x - 1)
				first_last_column(i, j, x, y);
			else
				middle_column(j, y);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void	first_last_column(int i, int j, int x, int y)
{
	if ((j == 0 && i == 0) || (j == y - 1 && i == x - 1))
		ft_putchar('A');
	else if ((j == (y - 1) && i == 0) || (j == 0 && i == (x - 1)))
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	middle_column(int j, int y)
{
	if (j == 0 || j == y - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}
