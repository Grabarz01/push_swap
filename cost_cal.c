/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_cal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:35:15 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 21:14:16 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_optim(int *a, int *b)
{
	int	r_r;

	if (*a < *b)
	{
		r_r = *a;
		*a = 0;
		*b = *b - r_r;
		return (r_r);
	}
	else if (*a > *b)
	{
		r_r = *b;
		*b = 0;
		*a = *a - r_r;
		return (r_r);
	}
	else
	{
		r_r = *a;
		*a = 0;
		*b = 0;
		return (r_r);
	}
}

void	ft_optimalization(t_cost *tmp_price)
{
	tmp_price->rr = ft_count_optim(&tmp_price->ra, &tmp_price->rb);
	tmp_price->rrr = ft_count_optim(&tmp_price->rra, &tmp_price->rrb);
	tmp_price->cost = tmp_price->rrb + tmp_price->rb + tmp_price->ra
		+ tmp_price->rra + tmp_price->rr + tmp_price->rrr;
}

void	ft_set_costs(t_cost *price)
{
	price->rr = 0;
	price->ra = 0;
	price->rb = 0;
	price->rra = 0;
	price->rrb = 0;
	price->rrr = 0;
	price->cost = INT_MAX;
}

void	ft_cost(t_cords* pos, t_limit *a_limits,
	t_limit *b_limits, t_cost *place)
{
	t_cost	tmp_price;

	ft_set_costs(&tmp_price);
	if (pos->a_pos < a_limits->size / 2)
		tmp_price.ra = pos->a_pos;
	else
		tmp_price.rra = a_limits->size - pos->a_pos;
	if (pos->b_pos < b_limits->size / 2)
		tmp_price.rb = pos->b_pos;
	else
		tmp_price.rrb = b_limits->size - pos->b_pos;
	ft_optimalization(&tmp_price);
	if (place->cost > tmp_price.cost)
	{
		place->ra = tmp_price.ra;
		place->rb = tmp_price.rb;
		place->rr = tmp_price.rr;
		place->rra = tmp_price.rra;
		place->rrb = tmp_price.rrb;
		place->rrr = tmp_price.rrr;
		place->cost = tmp_price.cost;
	}
}

void	ft_cost_cal(t_list *stack_a, t_list *stack_b, t_limit *a_limits,
	t_limit *b_limits)
{
	int	value;
	t_cords pos;
	t_cost place;

	ft_set_costs(&place);
	place.cost = a_limits->size + b_limits->size;
	pos.a_pos = 0;
	while (pos.a_pos < a_limits->size)
	{
		value = ft_get_value(stack_a, pos.a_pos);
		if (value > b_limits->max || value < b_limits->min)
		{
			pos.b_pos = ft_get_pos(stack_b, b_limits->max);
		}
		else
			pos.b_pos = ft_get_one_smaller(stack_b, value);
		ft_cost(&pos, a_limits, b_limits, &place);
		pos.a_pos++;
	}
	ft_replace(&stack_a, &stack_b, &place);
}
