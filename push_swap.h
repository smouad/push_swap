/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:14:48 by msodor            #+#    #+#             */
/*   Updated: 2023/02/13 20:17:55 by msodor           ###   ########.fr       */
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
	t_list	*top;
	int		size;
} t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}t_stacks;

//ckecker
void	error();
void	my_free(char **str);
int		check_args(char **str);
char	**all_args_splited(char **str);
int		is_proper_digit(char **str);
int		is_sorted(char **str);
int		check_doubles(char **str);
t_list	*list_args(char **str);

//rules && rules utils

int		pop(t_stack *stack);
void	push(t_stack *stack, int data);
t_stack	*create_stack(void);
void	swap(t_stack **stack);
void	rotate(t_list **list);
void	rrotate(t_list **list);
void	fill_stack(t_list *list, t_stack *stack);
void	sx(char x, t_stacks *stacks);
void	rx(char x, t_stacks *stacks);
void	rrx(char x, t_stacks *stacks);
void	px(char x, t_stacks *stacks);
void	push_ab(t_stack *stack, int data);


#endif