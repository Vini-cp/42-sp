/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:00:24 by vcordeir          #+#    #+#             */
/*   Updated: 2020/12/01 04:18:18 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int fat;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	fat = nb;
	while (nb > 1)
	{
		nb--;
		fat *= (nb);
	}
	return (fat);
}
