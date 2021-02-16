/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:26:14 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/13 21:37:11 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;

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

// int main()
// {
//     const char *largestring = "Foo Bar Baz";
//     const char *smallstring = "o B";
//     char *ptr;
//     char *ft_ptr;

//     ptr = strnstr(largestring, smallstring, 7);
//     ft_ptr = ft_strnstr(largestring, smallstring, 7);

//     printf("Funcao original: %s\n", ptr);
//     printf("FUncao criada: %s\n", ft_ptr);
// }