/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:33:44 by msodor            #+#    #+#             */
/*   Updated: 2023/02/23 19:09:59 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 5);
	exit(0);
}

t_list	*list_args(char **str)
{
	int		i;
	int		arg_count;
	t_list	*head;
	t_list	*new_node;
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
		new_node = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(&head, new_node);
		free(args[i]);
		i++;
	}
	free(args);
	return (head);
}

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
		all_args = my_strjoin(all_args, one_arg);
		free(one_arg);
		i++;
	}
	splited_args = ft_split(all_args, ' ');
	free(all_args);
	return (splited_args);
}

int	is_sorted(t_list *head)
{
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}
