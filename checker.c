/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:22:04 by msodor            #+#    #+#             */
/*   Updated: 2023/02/09 19:10:12 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//write Error on standard error and exit

void	error()
{
	write(2, "Error", 5);
	exit(0);
}

//gets tou all the argumments on a single string.
//show an error message if one of the arguments is empty.

char	*all_args(char **str)
{
	char *all_args;
	char *one_arg;
	int i;
	
	i = 1;
	all_args = malloc(1);
	all_args[0] = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) == 0)
			error();
		one_arg = ft_strjoin(str[i], " ");
		all_args = ft_strjoin(all_args, one_arg);
		free(one_arg);
		i++;
	}
	return (all_args);
}

//checks if the argument contain only spaces | tabs | new line

int	all_whitespace(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return(1);
		i++;
	}
	return(0);
}

int	check_args(char **str)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while(str[i][j])
	{
		if ()
		i++;
	}
	return (0);
}

