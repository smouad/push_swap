/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:36:20 by msodor            #+#    #+#             */
/*   Updated: 2023/02/23 18:23:47 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	content_index(int content, t_list *a_sorted)
{
	int	i;

	i = 1;
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
	i = 1;
	while (temp)
	{
		if (temp->content == bigest)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

void	push_to_b(t_stacks *stack, int min, int max)
{
	int	index;

	while (stack->a->size)
	{
		index = content_index(stack->a->top->content, stack->a_sorted);
		if (min <= index && index <= max)
		{
			px('b', stack);
			min++;
			max++;
		}
		if (index > max)
			rx('a', stack);
		if (min > index)
		{
			px('b', stack);
			rx('b', stack);
			min++;
			max++;
		}
	}
}

void	big_sort(t_stacks *stack)
{
	int	index;
	int	min;
	int	max;

	min = 0;
	max = 16;
	if (stack->a->size > 200)
		max = 34;
	push_to_b(stack, min, max);
	while (stack->b->size)
	{
		index = index_of_bigest(stack->b);
		while (stack->b->top->content != the_greatest(stack->b->top))
		{
			if (index <= stack->b->size / 2)
				rx('b', stack);
			if (index > stack->b->size / 2)
				rrx('b', stack);
		}
		px('a', stack);
	}
}
