/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:21:13 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 21:25:02 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_set_positions(t_list *stack_a, t_list *stack_b, t_limit *a_limits, t_limit *b_limits)
{
	int	pos;

	pos = 0;
	while (stack_a)
	{
		stack_a -> position = pos;
		pos++;
		stack_a = stack_a->lower;
	}
	a_limits->size = pos;
	pos = 0;
	while (stack_b)
	{
		stack_b -> position = pos;
		pos++;
		stack_b = stack_b->lower;
	}
	b_limits->size = pos;
}

void	ft_change_limits_taken(t_list *stack, t_limit *limits)
{
	if (limits -> size == 0)
	{
		limits->max = 0;
		limits->min = 0;
	}
	else if (limits -> size == 1)
	{
		limits->max = stack->number;
		limits->min = stack->number;
	}
	else
	{
		limits->max = ft_get_max(stack);
		limits->min = ft_get_min(stack);
	}
}

void	ft_change_limits_given(t_limit* limits, int value)
{
	if (limits -> size == 1)
	{
		limits->max = value;
		limits->min = value;
	}
	else
	{
		if (limits->max < value)
			limits->max = value;
		if (limits->min > value)
			limits->min = value;
	}
}

void	ft_replace(t_list **stack_a,t_list **stack_b, t_cost *place)
{
	while ((place->ra)-- > 0)
		ra(*stack_a);
	while ((place->rb)-- > 0)
		rb(*stack_b);
	while ((place->rr)-- > 0)
		rr(*stack_a,*stack_b);
	while ((place->rra)-- > 0)
		rra(*stack_a);
	while ((place->rrb)-- > 0)
		rrb(*stack_b);
	while ((place->rrr)-- > 0)
		rrr(*stack_a,*stack_b);
}

void	ft_end_move(t_list *stack_a, t_limit *a_limts)
{
	int				pos;

	pos = ft_get_pos(stack_a, a_limts->min);
	if (pos > a_limts->size / 2)
	{
		pos = a_limts->size - pos;
		while (pos-- > 0)
		{
			rra(stack_a);
		}
	}
	else
	{
		while (pos-- > 0)
		{
			ra(stack_a);
		}
	}
}
