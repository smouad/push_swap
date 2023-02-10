/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:14:48 by msodor            #+#    #+#             */
/*   Updated: 2023/02/10 19:43:58 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_stack
{
	t_list top;
	int size;
}t_stack;

void	error();
int		check_args(char **str);
char	**all_args_splited(char **str);
t_list	*list_args(char **str);
int		is_proper_digit(char **str);
int		is_sorted(char **str);




#endif