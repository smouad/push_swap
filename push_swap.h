/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:14:48 by msodor            #+#    #+#             */
/*   Updated: 2023/02/12 08:47:23 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct s_stack
{
	t_list	top;
	int		size;
}t_stack;

// typedef struct s_stacks
// {
// 	s_stack *stack;
	
// };


//ckecker
void	error();
void	my_free(char **str);
int		check_args(char **str);
char	**all_args_splited(char **str);
int		is_proper_digit(char **str);
int		is_sorted(char **str);
int		check_doubles(char **str);
t_list	*list_args(char **str);




#endif