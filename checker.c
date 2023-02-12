/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:22:04 by msodor            #+#    #+#             */
/*   Updated: 2023/02/12 08:07:04 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if the argument contain only spaces | tabs | new line

int	is_all_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

// check if all are proper degits

int	is_proper_digit(char **str)
{
	int		i;
	int		j;
	char	**spl_rags;

	i = 0;
	spl_rags = all_args_splited(str);
	while (spl_rags[i])
	{
		j = 0;
		while (spl_rags[i][j])
		{
			if (spl_rags[i][0] == '-' || spl_rags[i][0] == '+')
				j++;
			if (!ft_isdigit(spl_rags[i][j]) && ft_strlen(spl_rags[i]) > j)
				return (1);
			j++;
		}
		i++;
	}
	free(spl_rags);
	return (0);
}

//check for doubles on the list 

int	check_doubles(char **str)
{
	t_list	*head;
	int		tmp;
	t_list	*curr;

	head = list_args(str);
	while (head)
	{
		tmp = head->content;
		curr = head;
		while (curr->next)
		{
			if (tmp == curr->next->content)
				return (1);
			curr = curr->next;
		}
		head = head->next;
	}
	return (0);
}

// check all the arguments if one of them is all white space (Error)

int	check_args(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (is_all_whitespace(str[i]) || is_proper_digit(str) \
			|| check_doubles(str))
			return (1);
		i++;
	}
	return (0);
}
