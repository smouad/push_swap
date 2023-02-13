/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:27:43 by msodor            #+#    #+#             */
/*   Updated: 2023/02/13 14:53:28 by msodor           ###   ########.fr       */
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
		printf("sa\n");
	}
	if (x == 'b')
	{
		swap(&stacks->b);
		printf("sb\n");
	}
}

void	rx(char x, t_stacks *stacks)
{
	if (x == 'a')
	{
		rotate(&stacks->a->top);
		printf("ra\n");
	}
	if (x == 'b')
	{
		rotate(&stacks->b->top);
		printf("rb\n");
	}
}

void	rrx(char x, t_stacks *stacks)
{
	if (x == 'a')
	{
		rrotate(&stacks->a->top);
		printf("rra\n");
	}
	if (x == 'b')
	{
		rrotate(&stacks->b->top);
		printf("rrb\n");
	}
}

void	px(char x, t_stacks *stacks)
{
	if (x == 'b')
	{
		int temp;
		temp = pop(stacks->a);
		push_ab(stacks->b, temp);
		printf("pb\n");
	}
	if (x == 'a')
	{
		int temp;
		temp = pop(stacks->b);
		push_ab(stacks->a, temp);
		printf("pa\n");
	}
}