/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:22:04 by msodor            #+#    #+#             */
/*   Updated: 2023/02/10 14:48:51 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks if the argument contain only spaces | tabs | new line

int	is_all_whitespace(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

//check if all are proper degits

int	is_proper_digit(char **str)
{
	int i;
	int j;

	i = 1;
	str = all_args_splited(str);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][0] == '-' || str[i][0] == '+')
				j++;
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// check all the arguments if one of them is all white space (Error)

int	check_args(char **str)
{
	int i;

	i = 1;
	while(str[i])
	{
		if (is_all_whitespace(str[i]) || !is_proper_digit(str))
			return (1);
		i++;
	}
	return (0);
}