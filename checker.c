/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:22:04 by msodor            #+#    #+#             */
/*   Updated: 2023/02/11 08:54:12 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if the argument contain only spaces | tabs | new line

int is_all_whitespace(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

// check if all are proper degits

int is_proper_digit(char **str)
{
	int i;
	int j;
	char **splited_args;

	i = 0;
	splited_args = all_args_splited(str);
	while (splited_args[i])
	{
		j = 0;
		while (splited_args[i][j])
		{
			if (splited_args[i][0] == '-' || splited_args[i][0] == '+')
				j++;
			if (!ft_isdigit(splited_args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//check for doubles on the list

int check_doubles(char **str)
{
	t_list *head;
	int tmp;

	head = list_args(str);
	while (head)
	{
		tmp = head->content;
		while (head->next)
		{
			if (tmp == head->next->content)
				return (1);
			head->next = head->next->next;
		}
		head = head->next;
	}
	return (0);
}

// check all the arguments if one of them is all white space (Error)

int check_args(char **str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (is_all_whitespace(str[i]) || !is_proper_digit(str))
			return (1);
		i++;
	}
	return (0);
}
