/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:25:03 by msodor            #+#    #+#             */
/*   Updated: 2023/02/19 18:31:04 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*head = list_args(av);
	t_stacks	*stack = NULL;
	stack = malloc(sizeof(t_stacks));
	if (stack == NULL)
		exit(0);
	if (check_args(av))
		error();
	if (ac == 1 || is_sorted(head))
		exit(0);
	stack->a = create_stack();
	stack->b = create_stack();
	fill_stack(head, stack->a);
	aplly_rule(stack);
	if (is_sorted(stack->a->top))
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
}