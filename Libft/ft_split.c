/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:45:28 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/17 21:02:57 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	get_first_position(char const *str, char c, int start)
{
	while (str[start] == c)
		start++;
	return (start);
}

static	int	get_last_position(char const *str, char c, int start)
{
	while (str[start] != c && str[start] != '\0')
		start++;
	return (start);
}

static	int	nb_of_strs(char const *s, char c)
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

char		**ft_split(char const *s, char c)
{
	char	**strs;
	int		n;
	int		i;
	int		start;
	int		end;

	n = nb_of_strs(s, c);
	if (!(strs = (char**)malloc((n + 1) * sizeof(char*))))
		return (NULL);
	end = 0;
	i = 0;
	while (i < n)
	{
		start = get_first_position(s, c, end);
		end = get_last_position(s, c, start);
		if (!(strs[i] = (char*)malloc((end - start + 1) * sizeof(char))))
			return (NULL);
		ft_strlcpy(strs[i], (s + start), (end - start + 1));
		i++;
		end++;
	}
	if (!(strs[i] = (char*)malloc(sizeof(char))))
		return (NULL);
	strs[i] = NULL;
	return (strs);
}

// int main()
// {
// 	char **s;
// 	char str[] = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      .";
// 	char c = ' ';
	
// 	// char str[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
// 	// char c = ' ';
	
// 	// char str[] = "   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
// 	// char c = ' ';
	
// 	// char str[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.";
// 	// char c = 'i';
	
// 	// char str[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.";
// 	// char c = 'z';

// 	s = ft_split(str, c);
// 	while(*s)
// 		printf("%s|\n", *s++);
// }