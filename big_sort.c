/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:36:20 by msodor            #+#    #+#             */
/*   Updated: 2023/02/16 15:34:48 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *sort_list(t_list *list)
{
	t_list *list_head;
	int tmp;

	list_head = list;
	while (list_head->next)
	{
		if (list_head->content > list_head->next->content)
		{
			tmp = list_head->content;
			list_head->content = list_head->next->content;
			list_head->next->content = tmp;
		}
		list_head = list_head->next;
	}
	list_head = list;
	return (list_head);
}

