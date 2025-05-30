#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new2;

	if (!lst || !f || !del)
		return (0);
	new = ft_lstnew(f(lst->content));
	new2 = new;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&new2, del);
			return (NULL);
		}
		ft_lstadd_back(&new2, new);
		lst = lst->next;
	}
	return (new2);
}
