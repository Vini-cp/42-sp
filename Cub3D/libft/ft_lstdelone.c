#include "../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*next_node;

	next_node = NULL;
	if (lst != NULL)
	{
		next_node = lst->next;
		del(lst->content);
		free(lst);
		lst = next_node;
	}
}
