/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:44:22 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/29 23:55:26 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);
int		*ft_strcpy(int *dest, char *src);
void	call_err(void);
int		ft_atoi(char *str);
int		verify(int *ptr);
void	zero_tab(int *tab);
void	tab_fulfill(int *tab, int *ptr);

int		rush(int argc, char *argv[])
{
	int len;
	int *ptr;
	int tab[16];

	len = ft_strlen(argv[argc - 1]);
	ptr = malloc(sizeof(int) * len);
	if (len != 16 || ptr == NULL)
	{
		call_err();
		return (0);
	}
	ft_strcpy(ptr, argv[argc - 1]);
	if (!verify(ptr))
	{
		call_err();
		return (0);
	}
	zero_tab(tab);
	tab_fulfill(tab, ptr);
	free(ptr);
	return (1);
}
