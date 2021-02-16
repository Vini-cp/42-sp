/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:35:21 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/16 20:23:54 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_set_char(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static	int	get_first_position(char const *str, char const *set)
{
	int i;

	i = 0;
	while (is_set_char(str[i], set))
		i++;
	return (i);
}

static	int	get_last_position(char const *str, char const *set)
{
	int i;

	i = ft_strlen(str) - 1;
	while (is_set_char(str[i], set))
		i--;
	return (++i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		start;
	int		i;

	start = get_first_position(s1, set);
	len = get_last_position(s1, set) - start;
	if (len < 0)
	{
		if (!(str = (char *)malloc((sizeof(char)))))
			return (NULL);
		return (str);
	}
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
