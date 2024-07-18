/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:13:52 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 20:17:37 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max(t_list *stack)
{
	int	max;

	max = stack->number;
	while (stack->lower)
	{
		stack = stack->lower;
		if (stack->number > max)
			max = stack->number;
	}
	return (max);
}

int	ft_get_min(t_list *stack)
{
	int	min;

	min = stack->number;
	while (stack->lower)
	{
		stack = stack->lower;
		if (stack->number < min)
			min = stack->number;
	}
	return (min);
}

int	ft_sorted(t_list *stack)
{
	while (stack->lower)
	{
		if (stack->number > stack->lower->number)
			return (0);
		stack = stack->lower;
	}
	return (1);
}
