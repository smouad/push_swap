/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:27:43 by msodor            #+#    #+#             */
/*   Updated: 2023/02/14 12:04:22 by msodor           ###   ########.fr       */
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
	{
		swap(&stacks->a);
		write(1, "sa\n", 4);
	}
	if (x == 'b')
	{
		swap(&stacks->b);
		write(1, "sb\n", 4);
	}
}

void	rx(char x, t_stacks *stacks)
{
	if (x == 'a')
	{
		rotate(&stacks->a->top);
		write(1, "ra\n", 4);
	}
	if (x == 'b')
	{
		rotate(&stacks->b->top);
		write(1, "rb\n", 4);
	}
}

void	rrx(char x, t_stacks *stacks)
{
	if (x == 'a')
	{
		rrotate(&stacks->a->top);
		write(1, "rra\n", 5);
	}
	if (x == 'b')
	{
		rrotate(&stacks->b->top);
		write(1, "rrb\n", 5);
	}
}

void	px(char x, t_stacks *stacks)
{
	if (x == 'b')
	{
		int temp;
		temp = pop(stacks->a);
		push_ab(stacks->b, temp);
		write(1, "pb\n", 4);
	}
	if (x == 'a')
	{
		int temp;
		temp = pop(stacks->b);
		push_ab(stacks->a, temp);
		write(1, "pa\n", 4);
	}
}