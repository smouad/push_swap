/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:09:29 by msodor            #+#    #+#             */
/*   Updated: 2023/02/24 19:42:17 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	the_smalest(t_list *top)
{
	int	smallest;

	if (!top)
		return (0);
	smallest = top->content;
	while (top)
	{
		if (smallest > top->content)
			smallest = top->content;
		top = top->next;
	}
	return (smallest);
}

int	the_greatest(t_list *top)
{
	int	tmp;

	tmp = top->content;
	while (top)
	{
		if (top->content > tmp)
			tmp = top->content;
		top = top->next;
	}
	return (tmp);
}

void	sort_three(t_stacks *stack)
{
	int	smallest;
	int	greatest;

	while (is_sorted(stack->a->top) != 1)
	{
		smallest = the_smalest(stack->a->top);
		greatest = the_greatest(stack->a->top);
		if (stack->a->top->content == greatest \
			&& stack->a->top->next->content == smallest)
		{
			rx('a', stack);
			return ;
		}
		if (stack->a->top->content == smallest \
			|| stack->a->top->next->content == smallest)
			sx('a', stack);
		if (stack->a->top->content == greatest)
			rx('a', stack);
		if (stack->a->top->next->content == greatest)
			rrx('a', stack);
	}
}

int	index_of_smallest(t_stack *stack)
{
	int		i;
	int		smallest;
	t_list	*temp;

	temp = stack->top;
	smallest = the_smalest(temp);
	i = 1;
	while (temp)
	{
		if (temp->content == smallest)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

void	sort_five(t_stacks *stack)
{
	int	index;

	while (stack->a->size > 3)
	{
		index = index_of_smallest(stack->a);
		while (stack->a->top->content != the_smalest(stack->a->top))
		{
			if (index <= stack->a->size / 2)
				rx('a', stack);
			if (index > stack->a->size / 2)
				rrx('a', stack);
		}
		px('b', stack);
	}
	sort_three(stack);
	while (stack->b->size)
		px('a', stack);
}
