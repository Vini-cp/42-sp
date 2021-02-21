/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 20:47:52 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/19 20:48:25 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nb_of_strs(char const *s, char c)
{
	int nb;
	int bool_check;

	nb = 0;
	bool_check = 1;
	while (*s != '\0')
	{
		if (*s == c)
			bool_check = 1;
		else if (*s != c && bool_check)
		{
			nb++;
			bool_check = 0;
		}
		s++;
	}
	return (nb);
}

static	char	*string(const char *s, int init, int end)
{
	char	*str;

	str = (char*)malloc((end - init + 1) * sizeof(char));
	ft_strlcpy(str, (s + init), (end - init + 1));
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	int		start;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	start = -1;
	strs = malloc((nb_of_strs(s, c) + 1) * sizeof(char *));
	if (strs == 0)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			strs[j++] = string(s, start, i);
			start = -1;
		}
	}
	strs[j] = NULL;
	return (strs);
}
