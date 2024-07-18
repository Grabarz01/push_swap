/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:14:45 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 10:44:43 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_tiny_sort(t_list **stack_a)
{
	int	last;

	last = ft_get_value(*stack_a, 2);
	if (ft_sorted(*stack_a))
		return (0);
	if ((*stack_a)->number > last
		&& (*stack_a)->number > (*stack_a)->lower->number)
	{
		ra(*stack_a);
		if (ft_sorted(*stack_a))
			return (1);
		sa(*stack_a);
		return (2);
	}
	else if ((*stack_a)->number < last
		&& (*stack_a)->number < (*stack_a)->lower->number)
	{
		rra(*stack_a);
		sa(*stack_a);
		return (2);
	}
	else if ((*stack_a)->lower->number < last)
	{
		sa(*stack_a);
		return (1);
	}
	ra(*stack_a);
	ra(*stack_a);
	return (2);
}

unsigned int	ft_rot_stack_b(t_list *stack, t_limit *limits, t_cost *place)
{
	int				min_pos;
	unsigned int	price;

	ft_set_costs(place);
	price = 0;
	min_pos = ft_get_pos(stack, limits->min);
	if (min_pos > limits->size / 2)
		place->rrb = limits->size - min_pos - 1;
	else
		place->rb = min_pos + 1;
	price = place->rrb + place->rb;
	ft_replace(&stack, &stack, place);
	return (price);
}

unsigned int	ft_place_in_a(t_list **stack_a, t_list **stack_b,
	int value, t_limit *a_limits)
{
	int		pos;
	int		price;
	t_cost	place;

	ft_set_costs(&place);
	if (value > a_limits->max)
		pos = ft_get_pos(*stack_a, a_limits->min);
	else
		pos = ft_get_one_bigger(*stack_a, value);
	if (pos == 0)
		return (0);
	place.rra = a_limits->size - pos;
	price = place.rra;
	ft_replace(stack_a, stack_b, &place);
	return (price);
}

unsigned int	ft_empty_stack(t_list **stack_a, t_list **stack_b,
	t_limit *a_limits, t_limit *b_limits)
{
	unsigned int	price;

	price = 0;
	while (b_limits->size > 0)
	{
		price += ft_place_in_a(stack_a, stack_b, (*stack_b)->number, a_limits);
		pa(stack_a, stack_b, a_limits, b_limits);
		price++;
	}
	return (price);
}

unsigned int	ft_push_back(t_list **stack_a, t_list **stack_b, t_cost *place,
	t_limit *a_limits, t_limit *b_limits)
{
	unsigned int	price;

	price = 0;
	price += ft_rot_stack_b(*stack_b, b_limits, place);
	price += ft_empty_stack(stack_a, stack_b, a_limits, b_limits);
	return (price);
}
