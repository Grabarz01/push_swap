/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:28:44 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 10:37:12 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *stack)
{
	int	tmp;

	tmp = stack->number;
	stack->number = stack->lower->number;
	stack->lower->number = tmp;
}

void	ft_rotate(t_list *stack)
{
	int	tmp;

	tmp = stack->number;
	while (stack->lower)
	{
		stack->number = stack->lower->number;
		stack = stack->lower;
	}
	stack->number = tmp;
}

void	ft_rev_rotate(t_list *stack)
{
	int	tmp;

	while (stack->lower)
		stack = stack->lower;
	tmp = stack->number;
	while (stack->upper)
	{
		stack = stack->upper;
		stack ->lower->number = stack->number;
	}
	stack->number = tmp;
}
