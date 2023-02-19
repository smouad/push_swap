/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:16:32 by msodor            #+#    #+#             */
/*   Updated: 2023/02/19 18:45:44 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aplly_rule(t_stacks *stack)
{
	char	*rule;
	int 	len;
	
	rule = malloc(3);
	if (!rule)
		return ;
	while (1)
	{
		rule = get_next_line(0);
		len = ft_strlen(rule);
		if (ft_strncmp(rule, "sa\n", len) == 0)
			sx('a', stack);
		else if (ft_strncmp(rule, "sb\n", len) == 0)
			sx('b', stack);
		else if (ft_strncmp(rule, "ra\n", len) == 0)
			rx('a', stack);
		else if (ft_strncmp(rule, "rb\n", len) == 0)
			rx('b', stack);
		else if (ft_strncmp(rule, "rra\n", len) == 0)
			rrx('a', stack);
		else if (ft_strncmp(rule, "rrb\n", len) == 0)
			rrx('b', stack);
		else
			error();
	}
}
