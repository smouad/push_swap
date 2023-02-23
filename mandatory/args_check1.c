/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:22:04 by msodor            #+#    #+#             */
/*   Updated: 2023/02/23 18:18:23 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

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
		if (spl_rags[i][j] == '-' || spl_rags[i][j] == '+')
		{
			j++;
			if (ft_strlen(spl_rags[i]) == 1)
				return (1);
		}
		while (spl_rags[i][j])
		{
			if (!ft_isdigit(spl_rags[i][j++]))
				return (1);
		}
		free(spl_rags[i]);
		i++;
	}
	free(spl_rags);
	return (0);
}

int	check_doubles(t_list *head)
{
	int		tmp;
	t_list	*curr;

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

int	check_args(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (is_all_whitespace(str[i]) || is_proper_digit(str))
			return (1);
		i++;
	}
	return (0);
}
