/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:09:29 by msodor            #+#    #+#             */
/*   Updated: 2023/02/14 20:39:11 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_smalest(t_list *top)
{
	int	tmp;

	tmp = top->content;
	while (top)
	{
		if (tmp > top->content)
			tmp = top->content;
		top = top->next;
	}
	return (tmp);
}

int	is_greatest(t_list *top)
{
	int tmp;

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
	while (is_sorted(stack->a->top) != 1)
	{
		if (stack->a->top->content == is_greatest(stack->a->top) \
			&& stack->a->top->next->content == is_smalest(stack->a->top))
			{
				rx('a', stack);
				return ;
			}
		if (stack->a->top->content == is_smalest(stack->a->top) \
			|| stack->a->top->next->content == is_smalest(stack->a->top))
			sx('a', stack);
		if (stack->a->top->content == is_greatest(stack->a->top))
			rx('a', stack);
		if (stack->a->top->next->content == is_greatest(stack->a->top))
			rrx('a', stack);
	}
}

int	index_of_smallest(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->top->content != is_smalest(stack->top))
	{
		stack->top = stack->top->next;
		i++;
	}
	return (i);
}

void	sort_five(t_stacks *stack)
{
	int smallest;

	smallest = is_smalest(stack->a->top);
	while (stack->a->top->content != smallest)
	{
		if (index_of_smallest(stack->a) < stack->a->size / 2)
			rx('a', stack);
		else if (index_of_smallest(stack->a) > stack->a->size / 2)
			rrx('a', stack);
	}
	px('b', stack);
	// px('b', stack);
}