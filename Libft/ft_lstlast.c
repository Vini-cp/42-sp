/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:30:20 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/10 22:37:30 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst->next == NULL)
		return (lst);
	while (lst != NULL)
	{
		lst = lst->next;
		if (lst->next == NULL)
			return (lst);
	}
	return (NULL);
}
