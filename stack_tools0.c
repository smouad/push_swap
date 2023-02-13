/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:40:54 by msodor            #+#    #+#             */
/*   Updated: 2023/02/13 19:25:03 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

void	fill_stack(t_list *list, t_stack *stack)
{
	if (!list)
		return ;
	while (list)
	{
		push(stack, list->content);
		list = list->next;
	}
}

void	push(t_stack *stack, int data)
{
	t_list	*new_node;

	new_node = ft_lstnew(data);
	ft_lstadd_front(&stack->top, new_node);
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_list	*top;
	int		data;

	if (stack->size == 0)
		return (0);
	top = stack->top;
	stack->top = top->next;
	data = top->content;
	free(top);
	stack->size--;
	return (data);
}