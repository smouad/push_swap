/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:27:43 by msodor            #+#    #+#             */
/*   Updated: 2023/02/19 18:47:49 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_ab(t_stack *stack, int data)
{
	t_list	*new_node;

	new_node = ft_lstnew(data);
	ft_lstadd_front(&stack->top, new_node);
	stack->size++;
}

void	sx(char x, t_stacks *stacks)
{
	if (x == 'a')
		swap(&stacks->a);
	
	if (x == 'b')
		swap(&stacks->b);
}

void	rx(char x, t_stacks *stacks)
{
	if (x == 'a')
		rotate(&stacks->a->top);
	if (x == 'b')
		rotate(&stacks->b->top);
}

void	rrx(char x, t_stacks *stacks)
{
	if (x == 'a')
	rrotate(&stacks->a->top);
	if (x == 'b')
		rrotate(&stacks->b->top);
}

void	px(char x, t_stacks *stacks)
{
	if (x == 'b')
	{
		int temp;
		temp = pop(stacks->a);
		push_ab(stacks->b, temp);
	}
	if (x == 'a')
	{
		int temp;
		temp = pop(stacks->b);
		push_ab(stacks->a, temp);
	}
}