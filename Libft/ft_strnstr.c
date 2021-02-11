/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:26:14 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/10 22:32:53 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (little[i] == 0)
		return ((char *)big);
	while (big[i] != '\0' && len--)
	{
		if (big[i] == little[j])
			j++;
		else
			j = 0;
		if (little[j] == '\0')
		{
			p = (char *)&big[i - j + 1];
			return (p);
		}
		i++;
	}
	return (NULL);
}
