/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:25:03 by msodor            #+#    #+#             */
/*   Updated: 2023/02/20 11:09:45 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int ac, char **av)
// {
// 	t_list	*head = list_args(av);
// 	t_stacks	*stack = NULL;
// 	stack = malloc(sizeof(t_stacks));
// 	if (!stack)
// 		return 0;
// 	if (check_args(av))
// 		error();
// 	if (ac == 1 || is_sorted(head))
// 		exit(0);
// 	stack->a = create_stack();
// 	stack->b = create_stack();
// 	fill_stack(head, stack->a);
// 	char *rule = malloc(5);
// 	// rule = malloc(5);
// 	// if (!rule)
// 	// 	return (0);
// 	while (rule)
// 	{
// 		rule = get_next_line(0);
// 		aplly_rule(stack, rule);
// 	}
// 	if (is_sorted(stack->a->top))
// 		write(1, "ok\n", 3);
// 	else
// 		write(1, "ko\n", 3);
// }
int	main(int ac, char **av)
{
	t_list	*head = list_args(av);
	t_stacks	*stack = NULL;
	stack = malloc(sizeof(t_stacks));
	if (!stack)
		return 0;
	if (check_args(av))
		error();
	if (ac == 1 || is_sorted(head))
		exit(0);
	stack->a = create_stack();
	stack->b = create_stack();
	fill_stack(head, stack->a);
	apply_rule(stack);
	if (is_sorted(stack->a->top))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

