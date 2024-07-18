/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:03:34 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 13:10:03 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_top_node(t_list **stack_to_change, t_list **stack_to_free, int value)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
	{
		ft_free_nodes(stack_to_change);
		ft_free_nodes(stack_to_free);
		write(2, "Error\n", 6);
		exit(0);
	}
	tmp->number = value;
	tmp->upper = NULL;
	if (!*stack_to_change)
	{
		*stack_to_change = tmp;
		tmp->lower = NULL;
	}
	else
	{
		tmp->lower = *stack_to_change;
		(*stack_to_change)->upper = tmp;
		*stack_to_change = tmp;
	}
}

void	ft_add_node(t_list **stack_a, int a)
{
	t_list	*temp;
	t_list	*head;

	temp = malloc(sizeof(t_list));
	if (!temp)
	{
		write(2, "Error\n", 6);
		ft_free_nodes(stack_a);
		return ;
	}
	head = *stack_a;
	temp->number = a;
	if (!*stack_a)
	{
		*stack_a = temp;
		temp->upper = NULL;
	}
	else
	{
		while ((head)->lower != NULL)
			head = head->lower;
		head->lower = temp;
		temp->upper = head;
	}
	temp->lower = NULL;
}

void	ft_insert_arg(t_list **stack_a, char *arg)
{
	unsigned int	a;
	int		num;
	int 	minus;

	minus = ft_int_atoi(arg, &a);
	if (minus == 0)
	{
		ft_free_nodes(stack_a);
		return ;
	}
	num = a * minus;
	ft_add_node(stack_a, num);
}

void	ft_set_stack(t_list **stack_a, char **str)
{
	char	**args;
	int		i;
	int		y;

	i = 0;
	while (str[++i])
	{
		y = -1;
		args = ft_split(str[i], ' ');
		if (!args)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		while (args && args[++y])
		{
			ft_insert_arg(stack_a, args[y]);
			if (!(*stack_a))
			{
				ft_free_split(args);
				write(2, "Error\n", 6);
				exit(0);
			}
		}
		ft_free_split(args);
	}
}
