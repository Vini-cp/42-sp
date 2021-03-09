/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 22:30:52 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/08 21:22:45 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *next_node;

	head = NULL;
	while (lst != NULL)
	{
		if (!(next_node = ft_lstnew(f(lst->content))))
		{
			while (head)
			{
				next_node = head->next;
				del(head->content);
				free(head);
				head = next_node;
			}
			return (NULL);
		}
		ft_lstadd_back(&head, next_node);
		lst = lst->next;
	}
	return (head);
}
