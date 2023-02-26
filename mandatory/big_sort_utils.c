/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:53:42 by msodor            #+#    #+#             */
/*   Updated: 2023/02/26 13:57:35 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*list_coppy(t_list *list)
{
	t_list	*list_coppy;

	list_coppy = ft_lstnew(list->content);
	list = list->next;
	while (list)
	{
		ft_lstadd_back(&list_coppy, ft_lstnew(list->content));
		list = list->next;
	}
	return (list_coppy);
}

t_list	*sort_list(t_list *list)
{
	t_list	*list_cpy;
	t_list	*tmp;
	int		swap;

	list_cpy = list_coppy(list);
	tmp = list_cpy;
	while (list_cpy->next)
	{
		if (list_cpy->content > list_cpy->next->content)
		{
			swap = list_cpy->content;
			list_cpy->content = list_cpy->next->content;
			list_cpy->next->content = swap;
			list_cpy = tmp;
		}
		else
			list_cpy = list_cpy->next;
	}
	list_cpy = tmp;
	return (list_cpy);
}

int	content_index(int content, t_list *a_sorted)
{
	int	i;

	i = 0;
	while (a_sorted && a_sorted->content != content)
	{
		a_sorted = a_sorted->next;
		i++;
	}
	return (i);
}

int	index_of_bigest(t_stack *stack)
{
	int		i;
	int		bigest;
	t_list	*temp;

	temp = stack->top;
	bigest = the_greatest(temp);
	i = 0;
	while (temp)
	{
		if (temp->content == bigest)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}
