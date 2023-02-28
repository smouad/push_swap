/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:36:20 by msodor            #+#    #+#             */
/*   Updated: 2023/02/26 13:54:19 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stacks *stack, int min, int max)
{
	int	index;

	while (stack->a->size)
	{
		index = content_index(stack->a->top->content, stack->a_sorted);
		if (min > index)
		{
			px('b', stack);
			rx('b', stack);
			min++;
			max++;
		}
		if (min <= index && index <= max)
		{
			px('b', stack);
			min++;
			max++;
		}
		if (index > max)
			rx('a', stack);
	}
}

void	big_sort(t_stacks *stack)
{
	int	index;
	int	min;
	int	max;

	min = 0;
	max = 15;
	if (stack->a->size > 200)
		max = 40;
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
