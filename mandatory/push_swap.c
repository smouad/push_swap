/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:12:31 by msodor            #+#    #+#             */
/*   Updated: 2023/02/23 10:49:50 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stacks(t_stacks *stacks)
{
	free_list(stacks->a->top);
	free_list(stacks->b->top);
	free_list(stacks->a_sorted);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}

int main(int ac, char **av)
{
	t_stacks *stacks;
	stacks = malloc(sizeof(t_stacks));
	t_list *head = list_args(av);
	if (check_args(av) || check_doubles(head))
		error();
	if (ac == 1 || is_sorted(head))
		exit(0);
	stacks->a = create_stack();
	stacks->b = create_stack();
	stacks->a_sorted = sort_list(head);
	fill_stack(head, stacks->a);
	if (stacks->a->size <= 3)
		sort_three(stacks);
	if (stacks->a->size > 10)
		big_sort(stacks);
	if (stacks->a->size <= 10)
		sort_five(stacks);
	free_list(head);
	free_stacks(stacks);
}
