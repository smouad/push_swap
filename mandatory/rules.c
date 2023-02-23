/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:27:43 by msodor            #+#    #+#             */
/*   Updated: 2023/02/23 18:28:09 by msodor           ###   ########.fr       */
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
		write(1, "sa\n", 3);
	}
	if (x == 'b')
	{
		swap(&stacks->b);
		write(1, "sb\n", 3);
	}
	if (x == 's')
	{
		swap(&stacks->a);
		swap(&stacks->b);
		write(1, "ss\n", 3);
	}
}

void	rx(char x, t_stacks *stacks)
{
	if (x == 'a')
	{
		rotate(&stacks->a->top);
		write(1, "ra\n", 3);
	}
	if (x == 'b')
	{
		rotate(&stacks->b->top);
		write(1, "rb\n", 3);
	}
	if (x == 'r')
	{
		rotate(&stacks->a->top);
		rotate(&stacks->b->top);
		write(1, "rr\n", 3);
	}
}

void	rrx(char x, t_stacks *stacks)
{
	if (x == 'a')
	{
		rrotate(&stacks->a->top);
		write(1, "rra\n", 4);
	}
	if (x == 'b')
	{
		rrotate(&stacks->b->top);
		write(1, "rrb\n", 4);
	}
	if (x == 'r')
	{
		rrotate(&stacks->a->top);
		rrotate(&stacks->b->top);
		write(1, "rrr\n", 4);
	}
}

void	px(char x, t_stacks *stacks)
{
	int	temp;

	if (x == 'b')
	{
		temp = pop(stacks->a);
		push_ab(stacks->b, temp);
		write(1, "pb\n", 3);
	}
	if (x == 'a')
	{
		temp = pop(stacks->b);
		push_ab(stacks->a, temp);
		write(1, "pa\n", 3);
	}
}
