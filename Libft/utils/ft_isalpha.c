/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:54:23 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/02 21:54:24 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	ft_isalpha(int c)
{
	if ((c >= 'a' &&  c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
