/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:06:09 by vcordeir          #+#    #+#             */
/*   Updated: 2020/11/30 21:27:12 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rev_array(char *str)
{
	int		len;
	int		i;
	char	c;

	len = 0;
	i = 0;
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
}

char	*get_char(char *str, char *c, int *mult)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			*mult *= -1;
		else if (str[i] >= 48 && str[i] <= 57)
		{
			while ((str[i] >= '0' && str[i] <= '9')
				|| (str[i] >= 'A' && str[i] <= 'Z'))
			{
				c[j] = str[i];
				i++;
				j++;
			}
			c[j] = '\0';
			return (c);
		}
		i++;
	}
}

void	char_to_nb(char *str, int size, int *res)
{
	int pot;
	int i;

	pot = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A')
			*res += pot * (str[i] - 55);
		else
			*res += pot * (str[i] - '0');
		pot *= size;
		i++;
	}
}

int		verify(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j] != '\0' && i != j)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	else
		return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		mult;
	int		res;
	int		size;
	char	c[50];

	if (verify(base))
	{
		size = 0;
		while (base[size] != '\0')
		{
			size++;
		}
		mult = 1;
		res = 0;
		get_char(str, c, &mult);
		rev_array(c);
		char_to_nb(c, size, &res);
		return (res);
	}
	else
		return (0);
}
