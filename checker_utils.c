/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:33:44 by msodor            #+#    #+#             */
/*   Updated: 2023/02/10 19:50:27 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//write Error on standard error and exit

void	error()
{
	write(2, "Error", 5);
	exit(0);
}

//gets each argument and puts it on a linked list

t_list	*list_args(char **str)
{
	int i;
	int arg_count;
	t_list *head;
	char **args;

	arg_count = 0;
	i = 0;
	args = all_args_splited(str);
	while (args[arg_count])
		arg_count++;
	while (i <= arg_count)
	{
		ft_lstadd_back(&head ,ft_lstnew(ft_atoi(args[i])));
		i++;
	}
	return (head);
}

//gets tou all the arguments on a single string.
//show an error message if one of the arguments is empty.

char	**all_args_splited(char **str)
{
	char *all_args;
	char **all_args_splited;
	char *one_arg;
	int i;
	
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
	all_args_splited = ft_split(all_args, ' ');
	// free(all_args);
	return (all_args_splited);
}

int	is_sorted(char **str)
{
	t_list *head;

	head = list_args(str);
	while (head->next)
	{
		if (head->content > head->next->content)
			return(1);
		head = head->next;
	}
	return (0);
}