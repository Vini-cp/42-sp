#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*next_node;

	head = NULL;
	while (lst != NULL)
	{
		next_node = ft_lstnew(f(lst->content));
		if (!next_node)
		{
			while (head)
			{
				next_node = head->next;
				del(head->content);
				free(head);
				head = next_node;
			}
			return (NULL);
		}
		ft_lstadd_back(&head, next_node);
		lst = lst->next;
	}
	return (head);
}
