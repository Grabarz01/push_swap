/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:14:45 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 22:03:57 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tiny_sort(t_list **stack_a, int last)
{
	if (ft_sorted(*stack_a))
		return ;
	else if ((*stack_a)->number > last
		&& (*stack_a)->number > (*stack_a)->lower->number)
	{
		ra(*stack_a);
		if (ft_sorted(*stack_a))
			return ;
		sa(*stack_a);
	}
	else if ((*stack_a)->number < last
		&& (*stack_a)->number < (*stack_a)->lower->number)
	{
		rra(*stack_a);
		sa(*stack_a);
	}
	else if ((*stack_a)->lower->number < last)
		sa(*stack_a);
	else
	{
		ra(*stack_a);
		ra(*stack_a);
	}
}

void	ft_rot_stack_b(t_list *stack, t_limit *limits, t_cost *place)
{
	int		min_pos;

	ft_set_costs(place);
	min_pos = ft_get_pos(stack, limits->min);
	if (min_pos > limits->size / 2)
		place->rrb = limits->size - min_pos - 1;
	else
		place->rb = min_pos + 1;
	ft_replace(&stack, &stack, place);
}

void	ft_place_in_a(t_list **stack_a, t_list **stack_b,
	int value, t_limit *a_limits)
{
	int		pos;
	t_cost	place;

	ft_set_costs(&place);
	if (value > a_limits->max)
		pos = ft_get_pos(*stack_a, a_limits->min);
	else
		pos = ft_get_one_bigger(*stack_a, value);
	if (pos == 0)
		return ;
	place.rra = a_limits->size - pos;
	ft_replace(stack_a, stack_b, &place);
}

void	ft_empty_stack(t_list **stack_a, t_list **stack_b,
	t_limit *a_limits, t_limit *b_limits)
{
	
	while (b_limits->size > 0)
	{
		ft_place_in_a(stack_a, stack_b, (*stack_b)->number, a_limits);
		pa(stack_a, stack_b, a_limits, b_limits);
	}
}

void	ft_push_back(t_list **stack_a, t_list **stack_b, t_limit *a_limits, t_limit *b_limits)
{
	t_cost place;

	ft_set_costs(&place);
	ft_rot_stack_b(*stack_b, b_limits, &place);
	ft_empty_stack(stack_a, stack_b, a_limits, b_limits);
}
