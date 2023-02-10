/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:12:31 by msodor            #+#    #+#             */
/*   Updated: 2023/02/10 20:22:52 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	char **args = all_args_splited(av);
	if (ac == 1 || is_sorted(args))
		exit(0);
	if (check_args(av) )
		error();
	// char *a = all_args(av);
	// int *tab = tab_args(a);
	// int i = 0;
	// if (!is_proper_digit(av))
	// 	error();
	// while (i < 3)
	// {
	// 	printf("%d", tab[i]);
	// 	i++;
	// }
	
	
}
