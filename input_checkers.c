/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:57:07 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 10:35:52 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_args(t_list *stack_a)
{
	int	i;

	i = 1;
	while (stack_a->lower)
	{
		i++;
		stack_a = stack_a->lower;
	}
	return (i);
}

void	ft_duplicates(t_list **stack_a)
{
	int		value;
	t_list	*head;
	t_list	*check;

	head = (*stack_a)->lower;
	check = (*stack_a);
	value = (*stack_a)->number;
	while (check->lower)
	{
		while (check->lower)
		{
			if (check->lower->number == value)
			{
				ft_free_nodes(stack_a);
				write (2, "Error\n", 6);
				exit(0);
			}
			check = check->lower;
		}
		check = head;
		head = check->lower;
		value = check->number;//delete and use check->number
	}
}
//checks for chars different than digits and spaces
//and if arg is a number
//also changes tabs and newline to space for using the split function
//if we have two -/+ or +/- just after the number the input is wrong

char	*ft_arg_checker(char *arg)
{
	if (*arg && (*arg == '-' || *arg == '+'))
		arg++;
	if (!*arg || !(*arg >= '0' && *arg <= '9'))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	while (*arg && (*arg >= '0' && *arg <= '9'))
		arg++;
	if (!*arg || *arg == ' ' || *arg == '\t' || *arg == '\n')
		return (arg);
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_string_checker(char *str)
{
	if (!str || !*str)
		return (0);
	while (*str && *str == ' ')
		str++;
	if (!*str)
		return (0);
	while (*str && ((*str >= '0' && *str <= '9') || *str == ' '
			|| *str == '\t' || *str == '\n' || *str == '-' || *str == '+'))
	{
		if (*str == '\t' || *str == '\n')
			*str = ' ';
		if ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+')
			str = ft_arg_checker(str);
		else
			str++;
	}
	if (!*str)
		return (1);
	return (0);
}

void	ft_input_checker(char **strs)
{
	int	i;

	i = 1;
	while (strs[i])
	{
		if (ft_string_checker(strs[i]))
			i++;
		else
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
}
