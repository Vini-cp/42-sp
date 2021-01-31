/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:43:48 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/23 00:07:31 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	first_column(int j, int y);
void	middle_column(int j, int y);
void	last_column(int j, int y);
void	fir_mid_las_line(int j, int y, int i, int x);

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
			fir_mid_las_line(j, y, i, x);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void	fir_mid_las_line(int j, int y, int i, int x)
{
	if (i == 0)
		first_column(j, y);
	else if (i == x - 1)
		last_column(j, y);
	else
		middle_column(j, y);
}

void	first_column(int j, int y)
{
	if (j == 0)
		ft_putchar('/');
	else if (j == y - 1)
		ft_putchar('\\');
	else
		ft_putchar('*');
}

void	middle_column(int j, int y)
{
	if (j == 0 || j == y - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	last_column(int j, int y)
{
	if (j == 0)
		ft_putchar('\\');
	else if (j == y - 1)
		ft_putchar('/');
	else
		ft_putchar('*');
}
