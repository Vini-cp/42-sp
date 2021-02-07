/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:57:08 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 17:37:19 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list * head;
    
    head = NULL;
    head = (t_list *) malloc(sizeof(t_list));
    
    head->content = content;
    head->next = NULL;

    return head;
}