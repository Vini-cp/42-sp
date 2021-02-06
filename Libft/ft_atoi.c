/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:53:57 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 16:47:12 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int i;
	int mult;
	int res;
	int bool_first;

	i = 0;
	res = 0;
	mult = 1;
	bool_first = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && bool_first)
		{
			mult = -1;
			bool_first = 0;
		}
		else if (str[i] == '+' && bool_first)
			bool_first = 0;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				res = res * 10 + str[i] - '0';
				i++;
			}
			return (mult * res);
		}
		else if ((str[i] < 7 || str[i] > 13) && str[i] != 32)
			return(0);
		i++;
	}
	return(0);
}
