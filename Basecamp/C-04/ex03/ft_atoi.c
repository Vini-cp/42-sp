/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 04:05:00 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/30 20:49:45 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int mult;
	int res;

	i = 0;
	mult = 1;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			mult *= -1;
		else if (str[i] >= 48 && str[i] <= 57)
		{
			while (str[i] >= 48 && str[i] <= 57)
			{
				res = res * 10 + str[i] - '0';
				i++;
			}
			return (mult * res);
		}
		i++;
	}
}
