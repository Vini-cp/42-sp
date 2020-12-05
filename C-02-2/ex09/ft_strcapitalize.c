/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:12:09 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/26 23:25:22 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int first;

	i = 0;
	first = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122 && first)
		{
			str[i] -= 32;
			first = 0;
		}
		else if (str[i] >= 48 && str[i] <= 57)
			first = 0;
		if (str[i] < 48 || (str[i] >= 58 && str[i] <= 64) ||
			(str[i] >= 91 && str[i] <= 96) || (str[i] >= 123 && str[i] <= 127))
			first = 1;
		i++;
	}
	return (str);
}
