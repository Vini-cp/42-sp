/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 22:46:17 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/11 00:15:44 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *next_node;

	next_node = NULL;
	while ((*lst) != NULL)
	{
		next_node = (*lst)->next;
		del((*lst)->content);
        free(*lst);
		(*lst) = next_node;
	}
}
