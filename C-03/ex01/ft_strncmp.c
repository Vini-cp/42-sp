/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:10:21 by vcordeir          #+#    #+#             */
/*   Updated: 2020/12/02 02:00:18 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int        ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;

    if (n == 0)
        return (0);
    i = 0;
    while ((s1[i] != '\0' || s2[i] != '\0') && i < n - 1)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}
