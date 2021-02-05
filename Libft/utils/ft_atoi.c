/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:53:57 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/02 21:54:03 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int i;
	int mult;
	int res;

	i = 0;
	mult = 1;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && mult == 1)
			mult = -1;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				res = res * 10 + str[i] - '0';
				i++;
			}
			return (mult * res);
		}
		else
			return(0);
		i++;
	}
	return(0);
}
