/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:12:31 by msodor            #+#    #+#             */
/*   Updated: 2023/02/12 09:02:03 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	// printf("%d", ft_atoi("12"));
	t_list *head = list_args(av);
	(void)head;
	if (check_args(av))
		error();
	if (ac == 1 || is_sorted(av) )
		exit(0);
	while (head)
	{
		printf("%d ", head->content);
		head = head->next;
	}
}
