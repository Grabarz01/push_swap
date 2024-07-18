/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:18:17 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 09:30:39 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns position of the number smaller than the value(nearest)
int	ft_get_one_smaller(t_list *stack, int value)
{
	int	pos;
	int	num;

	while (stack->number >= value)
		stack = stack->lower;
	num = stack->number;
	pos = stack->position;
	while (stack->lower)
	{
		stack = stack->lower;
		if (num < stack->number && stack->number < value)
		{
			pos = stack->position;
			num = stack->number;
		}
	}
	return (pos);
}
//returns the position of the specified position from the specified stack

int	ft_get_pos(t_list *stack, int value)
{
	int	i;

	i = 0;
	while (value != stack->number)
	{
		stack = stack->lower;
		i++;
	}
	return (i);
}
//returns the value at the specified position from the specified stack

int	ft_get_value(t_list *stack, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		stack = stack->lower;
		i++;
	}
	return (stack->number);
}

int	ft_get_one_bigger(t_list *stack, int value)
{
	int	tmp;
	int	pos;

	while (stack->number < value)
		stack = stack->lower;
	tmp = stack->number;
	pos = stack->position;
	while (stack->lower)
	{
		stack = stack->lower;
		if (stack->number > value && stack->number < tmp)
		{
			tmp = stack->number;
			pos = stack->position;
		}
	}
	return (pos);
}