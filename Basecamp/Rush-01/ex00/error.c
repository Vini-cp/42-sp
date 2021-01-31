/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:22:15 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/29 22:40:04 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	call_err(void)
{
	char	*err;
	int		i;

	i = 0;
	err = "Error\n";
	while (err[i] != '\0')
	{
		ft_putchar(err[i]);
		i++;
	}
}
