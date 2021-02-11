/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:57:08 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/11 00:19:15 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if(!(new = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
