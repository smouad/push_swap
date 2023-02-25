t_list	*sort_list(t_list *list)
{
	t_list	*sorted_list;

	sorted_list = ft_lstnew(list->content);
	list = list->next;
	while (list != NULL)
	{
		t_list *curr = sorted_list;
		t_list *prev = NULL;
		while (curr != NULL && list->content > curr->content)
		{
			prev = curr;
			curr = curr->next;
		}
		if (prev == NULL)
		{
			ft_lstadd_front(&sorted_list, ft_lstnew(list->content));
		}
		else
		{
			prev->next = ft_lstnew(list->content);
			prev->next->next = curr;
		}
		list = list->next;
	}
	return (sorted_list);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}