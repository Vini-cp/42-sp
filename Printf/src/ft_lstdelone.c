/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 22:13:41 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/08 21:22:45 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list *next_node;

	next_node = NULL;
	if (lst != NULL)
	{
		next_node = lst->next;
		del(lst->content);
		free(lst);
		lst = next_node;
	}
}
