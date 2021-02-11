/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 22:30:52 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/10 21:31:40 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list * head;
	// t_list * tmp;
	t_list * next_node;
	
	next_node = NULL;
	while (lst != NULL)
	{
		f(lst->content);
		head = lst;
		next_node = lst->next;
		del(lst);
		lst = next_node;
	}
	return head;
}