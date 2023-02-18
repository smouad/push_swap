/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:25:03 by msodor            #+#    #+#             */
/*   Updated: 2023/02/18 11:44:48 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_list	*head;
	t_stacks	*stack = NULL;
	head = list_args(av);
	if (check_args(av))
		error();
	if (ac == 1 || is_sorted(head))
		exit(0);
	aplly_rule(stack);
}