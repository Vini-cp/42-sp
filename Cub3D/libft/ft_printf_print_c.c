#include "../include/libft.h"

static	int	print_just(t_flags *lst)
{
	if (lst->width > 0)
	{
		ft_putchar_fd(lst->print_c, 1);
		ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - 1), 1);
	}
	else
		ft_putchar_fd(lst->print_c, 1);
	return (ft_max(1, lst->width));
}

static	int	print_not_just(t_flags *lst)
{
	if (lst->width > 0)
	{
		if (lst->print_c == '%' && lst->zero)
			ft_putstr_fd(ft_substr(lst->f, 0, lst->width - 1), 1);
		else
			ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - 1), 1);
		ft_putchar_fd(lst->print_c, 1);
	}
	else
		ft_putchar_fd(lst->print_c, 1);
	return (ft_max(1, lst->width));
}

int	ft_printf_print_c(t_flags *lst)
{
	int	i;

	i = 0;
	lst->s_len = 1;
	if (lst->just)
		i = print_just(lst);
	else
		i = print_not_just(lst);
	return (i);
}
