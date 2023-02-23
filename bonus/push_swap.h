/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:14:48 by msodor            #+#    #+#             */
/*   Updated: 2023/02/23 19:50:41 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_list	*a_sorted;
}	t_stacks;

// args check

void	error(void);
void	free_list(t_list *head);
int		check_args(char **str);
char	**all_args_splited(char **str);
int		is_proper_digit(char **str);
int		is_sorted(t_list *head);
int		check_doubles(t_list *head);
t_list	*list_args(char **str);

// rules && rules utils

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

// small sort

int		the_smalest(t_list *top);
int		the_greatest(t_list *top);
void	sort_three(t_stacks *stack);
int		index_of_smallest(t_stack *stack);
void	sort_five(t_stacks *stack);

// big sort

t_list	*sort_list(t_list *list);
void	push_to_b(t_stacks *stack, int min, int max);
void	big_sort(t_stacks *stack);
int		index_of_bigest(t_stack *stack);
int		content_index(int content, t_list *a_sorted);

//GNL

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 29
#endif

int		my_strlen(char *str);
int		my_strchr(char *str, char c);
char	*my_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif