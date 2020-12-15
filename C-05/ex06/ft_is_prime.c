/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:20:37 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/30 21:52:28 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;
	int prime;

	if (nb <= 1)
		return (0);
	i = 2;
	prime = 1;
	while (i < nb)
	{
		if (nb % i == 0)
			prime = 0;
		i++;
	}
	return (prime);
}
