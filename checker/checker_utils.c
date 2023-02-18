/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:16:32 by msodor            #+#    #+#             */
/*   Updated: 2023/02/18 12:03:30 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	aplly_rule(t_stacks *stack)
{
	char	*rule;
	int 	len;
	
	rule = malloc(3);
	if (!rule)
		return ;
	while (get_next_line(0) != NULL)
	{
		rule = get_next_line(0);
		len = ft_strlen(rule);
		if (!ft_strncmp(rule, "sa\n", len))
			sx('a', stack);
		if (!ft_strncmp(rule, "sb\n", len))
			sx('b', stack);
		if (!ft_strncmp(rule, "ra\n", len))
			rx('a', stack);
		if (!ft_strncmp(rule, "rb\n", len))
			rx('b', stack);
		if (!ft_strncmp(rule, "rra\n", len))
			rrx('a', stack);
		if (!ft_strncmp(rule, "rrb\n", len))
			rrx('b', stack);
		else
			error();
	}
}
