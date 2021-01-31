/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:10:49 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/26 23:24:32 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_nb(char c)
{
	if (c < 10)
		c += 48;
	else
		c += 87;
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 16)
		{
			write(1, "\\0", 2);
			check_nb(str[i] % 16);
		}
		else if (str[i] < 32)
		{
			write(1, "\\1", 2);
			check_nb(str[i] % 16);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
