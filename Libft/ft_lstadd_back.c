/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:36:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 19:40:24 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;
    
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    last = ft_lstlast(*lst);
    last->next = new;
    new->next = NULL;
}
