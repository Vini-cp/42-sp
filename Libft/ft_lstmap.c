/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 22:30:52 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 23:09:42 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list * head;
    t_list * node;
    
    if (lst != NULL)
        head = ft_lstnew(f(lst->content));
    lst = lst->next;
    while (lst != NULL)
    {
        node = ft_lstnew(f(lst->content));
        ft_lstadd_back(&head, node);
        
    }
    
    
}