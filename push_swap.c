/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:12:31 by msodor            #+#    #+#             */
/*   Updated: 2023/02/12 19:11:22 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *head = list_args(av);
	if (check_args(av))
		error();
	if (ac == 1 || is_sorted(av) )
		exit(0);
	t_stack *stack_a;
	stack_a = create_stack();
	while (head)
	{
		push(stack_a, head->content);
		printf("%d ", stack_a->top->content);
		head = head->next;
	}
		printf("\n");
	int t = pop(stack_a);
		printf("%d ", t);
		printf("\n");
	while(stack_a->top)
	{
		printf("%d ", stack_a->top->content);
		stack_a->top = stack_a->top->next;
	}
	
}
