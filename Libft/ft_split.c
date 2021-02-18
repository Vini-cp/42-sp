/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:45:28 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/17 22:28:43 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		get_first_position(char const *str, char c, int start)
{
	while (str[start] == c)
		start++;
	return (start);
}

static	int		get_last_position(char const *str, char c, int start)
{
	while (str[start] != c && str[start] != '\0')
		start++;
	return (start);
}

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

static	char	**str_null(char **s)
{
	char	**str;
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
		return (NULL);
	}
	else
	{
		if (!(str = (char**)malloc(sizeof(char*))))
			return (NULL);
		str[0] = NULL;
		return (str);
	}
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	int		n;
	int		i;
	int		start;
	int		end;

	end = 0;
	i = 0;
	if (s == NULL)
		return (str_null(NULL));
	n = nb_of_strs(s, c);
	if (!(strs = (char**)malloc((n + 1) * sizeof(char*))))
		return (NULL);
	while (i < n)
	{
		start = get_first_position(s, c, end);
		end = get_last_position(s, c, start);
		if (!(strs[i] = (char*)malloc((end - start + 1) * sizeof(char))))
			str_null(strs);
		ft_strlcpy(strs[i++], (s + start), (end++ - start + 1));
	}
	if (!(strs[i] = (char*)malloc(sizeof(char))))
		return (NULL);
	strs[i] = NULL;
	return (strs);
}
