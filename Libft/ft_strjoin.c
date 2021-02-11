/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 23:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/10 22:44:44 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*strjoin;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(strjoin = (char*)malloc((len_s1 + len_s2 + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (i < len_s2 + len_s1)
	{
		strjoin[i] = s2[i - len_s1];
		i++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}
