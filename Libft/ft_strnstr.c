/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:26:14 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/16 22:11:37 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && len--)
	{
		if (big[i] == little[j])
			j++;
		else
		{
			if (i)
				i -= j;
			j = 0;
		}
		if (!little[j])
			return ((char *)&big[i - j + 1]);
		i++;
	}
	return (NULL);
}
