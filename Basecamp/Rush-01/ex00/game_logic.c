/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 23:46:22 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/30 01:19:31 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	write_tab(int *tab);
void	ft_putchar(char c);
void	find_four_and_one_col(int *tab, int *ptr);
void	find_four_and_one_lin(int *tab, int *ptr);
void	find_two_and_one_col(int *tab, int *ptr);
void	find_two_and_one_lin(int *tab, int *ptr);

void	tab_fulfill(int *tab, int *ptr)
{
	int		i;
	char	c;

	find_four_and_one_col(tab, ptr);
	find_four_and_one_lin(tab, ptr);
	find_two_and_one_col(tab, ptr);
	find_two_and_one_lin(tab, ptr);
	i = 0;
	while (i < 16)
	{
		c = tab[i] + '0';
		if ((i + 1) % 4 == 0)
		{
			ft_putchar(c);
			ft_putchar('\n');
		}
		else
		{
			ft_putchar(c);
			ft_putchar(' ');
		}
		i++;
	}
}

void	find_four_and_one_col(int *tab, int *ptr)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((ptr[i] == 1 && ptr[i + 4] == 4) ||
			(ptr[i + 4] == 1 && ptr[i] == 4))
		{
			if (ptr[i] == 1)
			{
				tab[i] = 4;
				tab[i + 4] = 3;
				tab[i + 8] = 2;
				tab[i + 12] = 1;
			}
			else if (ptr[i] == 4)
			{
				tab[i] = 1;
				tab[i + 4] = 2;
				tab[i + 8] = 3;
				tab[i + 12] = 4;
			}
		}
		i++;
	}
}

void	find_four_and_one_lin(int *tab, int *ptr)
{
	int i;

	i = 8;
	while (i < 12)
	{
		if ((ptr[i] == 1 && ptr[i + 4] == 4) ||
			(ptr[i + 4] == 1 && ptr[i] == 4))
		{
			if (ptr[i] == 1)
			{
				tab[(i % 4) * 4] = 4;
				tab[(i % 4) * 4 + 1] = 3;
				tab[(i % 4) * 4 + 2] = 2;
				tab[(i % 4) * 4 + 3] = 1;
			}
			else if (ptr[i] == 4)
			{
				tab[(i % 4) * 4] = 1;
				tab[(i % 4) * 4 + 1] = 2;
				tab[(i % 4) * 4 + 2] = 3;
				tab[(i % 4) * 4 + 3] = 4;
			}
		}
		i++;
	}
}

void	find_two_and_one_col(int *tab, int *ptr)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((ptr[i] == 1 && ptr[i + 4] == 2) ||
			(ptr[i + 4] == 1 && ptr[i] == 2))
		{
			if (ptr[i] == 1)
			{
				tab[i] = 4;
				tab[i + 12] = 3;
			}
			else if (ptr[i] == 2)
			{
				tab[i] = 3;
				tab[i + 12] = 4;
			}
		}
		i++;
	}
}

void	find_two_and_one_lin(int *tab, int *ptr)
{
	int i;

	i = 8;
	while (i < 12)
	{
		if ((ptr[i] == 1 && ptr[i + 4] == 2) ||
			(ptr[i + 4] == 1 && ptr[i] == 2))
		{
			if (ptr[i] == 1)
			{
				tab[(i % 4) * 4] = 4;
				tab[(i % 4) * 4 + 3] = 3;
			}
			else if (ptr[i] == 2)
			{
				tab[(i % 4) * 4] = 3;
				tab[(i % 4) * 4 + 3] = 4;
			}
		}
		i++;
	}
	i = 0;
}
