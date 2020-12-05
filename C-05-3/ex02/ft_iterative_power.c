/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:25:55 by vcordeir          #+#    #+#             */
/*   Updated: 2020/12/01 04:05:47 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int aux;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	aux = nb;
	while (power > 1)
	{
		nb *= aux;
		power--;
	}
	return (nb);
}
