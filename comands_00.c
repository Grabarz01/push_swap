/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:27:27 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 10:25:56 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *stack_a)
{
	write(1, "rra\n", 4);
	ft_rev_rotate(stack_a);
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	write(1, "rrr\n", 4);
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
}

void	rrb(t_list *stack_b)
{
	write(1, "rrb\n", 4);
	ft_rev_rotate(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b,
	t_limit *a_limits, t_limit *b_limits)
{
	int	tmp;

	tmp = (*stack_b)->number;
	if ((*stack_b)->lower)
	{
		*stack_b = (*stack_b)->lower;
		free((*stack_b)->upper);
		(*stack_b)->upper = NULL;
	}
	else
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	ft_top_node(stack_a, stack_b, tmp);
	ft_set_positions(*stack_a, *stack_b, a_limits, b_limits);
	ft_change_limits_taken(*stack_b, b_limits);
	ft_change_limits_given(a_limits, tmp);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b,
		t_limit *a_limits, t_limit *b_limits)
{
	int	tmp;

	tmp = (*stack_a)->number;
	*stack_a = ((*stack_a)->lower);
	free((*stack_a)->upper);
	(*stack_a)->upper = NULL;
	ft_top_node(stack_b, stack_a, tmp);
	ft_set_positions(*stack_a, *stack_b, a_limits, b_limits);
	ft_change_limits_taken(*stack_a, a_limits);
	ft_change_limits_given(b_limits, tmp);
	write(1, "pb\n", 3);
}