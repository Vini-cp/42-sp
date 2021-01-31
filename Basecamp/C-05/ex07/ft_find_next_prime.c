/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:41:27 by vcordeir          #+#    #+#             */
/*   Updated: 2020/12/01 04:11:59 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb);

int		ft_find_next_prime(int nb)
{
	int prime;

	prime = ft_is_prime(nb);
	while (!prime)
	{
		nb++;
		prime = ft_is_prime(nb);
	}
	return (nb);
}

int		ft_is_prime(int nb)
{
	int i;
	int prime;

	if (nb <= 1 || nb % 2 == 0)
		return (0);
	i = 3;
	prime = 1;
	while (i < nb)
	{
		if (nb % i == 0)
			prime = 0;
		i++;
	}
	return (prime);
}
