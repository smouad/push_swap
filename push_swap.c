/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:12:31 by msodor            #+#    #+#             */
/*   Updated: 2023/02/11 08:55:20 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	// printf("%d", ft_atoi("12"));
	t_list *head = list_args(av);
	(void)head;
	if (ac == 1 || is_sorted(av) )
		exit(0);
	if (check_args(av) || check_doubles(av))
		error();
	while (head)
	{
		printf("%d ", head->content);
		head = head->next;
	}
}
