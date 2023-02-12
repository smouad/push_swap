/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:33:44 by msodor            #+#    #+#             */
/*   Updated: 2023/02/12 09:07:46 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// write Error on standard error and exit

void	error(void)
{
	write(2, "Error", 5);
	exit(0);
}

//free a two dimention array

void	my_free(char **str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
}

// gets each argument and puts it on a linked list
//and if value is greter tan INT_MAX or XXXX (less than INT_MIN) XXXX

t_list	*list_args(char **str)
{
	int		i;
	int		arg_count;
	t_list	*head;
	char	**args;

	head = NULL;
	i = 0;
	arg_count = 0;
	args = all_args_splited(str);
	while (args[arg_count])
		arg_count++;
	while (i < arg_count)
	{
		if (ft_atoi(args[i]) < INT_MIN || ft_atoi(args[i]) > INT_MAX)
			error();
		ft_lstadd_back(&head, ft_lstnew(ft_atoi(args[i])));
		i++;
	}
	my_free(args);
	return (head);
}

// gets tou all the arguments on a single string.
// show an error message if one of the arguments is empty.

char	**all_args_splited(char **str)
{
	char	*all_args;
	char	**splited_args;
	char	*one_arg;
	int		i;

	i = 1;
	all_args = malloc(1);
	all_args[0] = '\0';
	while (str[i])
	{
		if (ft_strlen(str[i]) == 0)
			error();
		one_arg = ft_strjoin(str[i], " ");
		all_args = ft_strjoin(all_args, one_arg);
		free(one_arg);
		i++;
	}
	splited_args = ft_split(all_args, ' ');
	free(all_args);
	return (splited_args);
}

// check if the list is already sorted returns 1 if it's sorted

int	is_sorted(char **str)
{
	t_list	*head;

	head = list_args(str);
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}
