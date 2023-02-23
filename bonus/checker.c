/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:25:03 by msodor            #+#    #+#             */
/*   Updated: 2023/02/23 18:54:26 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rule(char *rule, t_stacks *stack, int len)
{
		if (ft_strncmp(rule, "sa\n", len) == 0)
			sx('a', stack);
		else if (ft_strncmp(rule, "sb\n", len) == 0)
			sx('b', stack);
		else if (ft_strncmp(rule, "ss\n", len) == 0)
			sx('s', stack);
		else if (ft_strncmp(rule, "ra\n", len) == 0)
			rx('a', stack);
		else if (ft_strncmp(rule, "rb\n", len) == 0)
			rx('b', stack);
		else if (ft_strncmp(rule, "rr\n", len) == 0)
			rx('r', stack);
		else if (ft_strncmp(rule, "rra\n", len) == 0)
			rrx('a', stack);
		else if (ft_strncmp(rule, "rrb\n", len) == 0)
			rrx('b', stack);
		else if (ft_strncmp(rule, "rrr\n", len) == 0)
			rrx('r', stack);
		else if (ft_strncmp(rule, "pa\n", len) == 0)
			px('a', stack);
		else if (ft_strncmp(rule, "pb\n", len) == 0)
			px('b', stack);
		else
			error();
		free(rule);
}

void	apply_rule(t_stacks *stack)
{
	char	*rule;
	rule = NULL;
	while ((rule = get_next_line(0)))
		check_rule(rule, stack, 5);
}

int	main(int ac, char **av)
{
	t_list		*head;
	t_stacks	*stack = NULL;

	head = list_args(av);
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

