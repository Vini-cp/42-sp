/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:39:53 by vcordeir          #+#    #+#             */
/*   Updated: 2020/12/04 23:05:49 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <stdbool.h>
# include <unistd.h>

int		EVEN(int nbr)
{
	if (nbr % 2 == 0)
		return (1);
	else
		return (0);
}

char *EVEN_MSG = "I have an even number of arguments.";
char *ODD_MSG = "I have an odd number of arguments.";
int SUCCESS = 0;

bool TRUE = true;
bool FALSE = false;

typedef bool	t_bool;
#endif
