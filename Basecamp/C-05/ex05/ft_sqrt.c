/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:43:48 by vcordeir          #+#    #+#             */
/*   Updated: 2020/12/01 20:27:39 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	next_it(int *i, int nb, int flag)
{
	if (flag < 50)
		*i = *i - ((*i * *i) - nb) / (2 * *i);
	else
	{
		if (((*i * *i) - nb) > 0)
		{
			*i -= 1;
		}
		else
			*i += 1;
	}
}

int		first_approach(int nb)
{
	int i;

	if (nb > 1000000000)
		i = nb / 100000;
	else if (nb > 100000000)
		i = nb / 20000;
	else if (nb > 1000000)
		i = nb / 10000;
	else if (nb > 100000)
		i = nb / 10000;
	else if (nb > 10000)
		i = nb / 1000;
	else if (nb > 100)
		i = nb / 100;
	else if (nb > 10)
		i = nb / 2;
	else
		i = nb;
	return (i);
}

int		ft_sqrt(int nb)
{
	int i;
	int flag;

	if (nb <= 0)
		return (0);
	i = first_approach(nb);
	flag = 0;
	while ((nb - i * i) != 0)
	{
		next_it(&i, nb, flag);
		flag++;
		if (flag == 200)
			return (0);
	}
	return (i);
}
