/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:55:43 by msodor            #+#    #+#             */
/*   Updated: 2023/02/13 14:56:32 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!(*stack) || !(*stack)->top || !(*stack)->top->next)
		return ;
	tmp1 = (*stack)->top;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	(*stack)->top = tmp2;
}

void	rotate(t_list **list)
{
	t_list	*temp;
	t_list	*current;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	current = *list;
	while (current->next != NULL)
		current = current->next;
	temp = *list;
	*list = (*list)->next;
	current->next = temp;
	temp->next = NULL;
}

void	rrotate(t_list **list)
{
	t_list	*temp;
	t_list	*current;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	current = *list;
	while (current->next->next != NULL)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = *list;
	*list = temp;
}
