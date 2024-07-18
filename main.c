/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:46:52 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 10:34:58 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_all_sort(t_list **stack_a, t_list **stack_b, t_limit *a_limits,
unsigned int *whole_cost)
{
	t_cost	place;
	t_limit	b_limits;

	b_limits.size = 0;
	pb(stack_a, stack_b, a_limits, &b_limits);
	pb(stack_a, stack_b, a_limits, &b_limits);
	*whole_cost += 2;
	place.cost = a_limits->size + b_limits.size;
	while (a_limits->size > 3)
	{
		place.cost = a_limits->size + b_limits.size;
		ft_cost_cal(*stack_a, *stack_b, a_limits, &b_limits, &place);
		*whole_cost += place.cost;
		ft_replace(stack_a, stack_b, &place);
		pb(stack_a, stack_b, a_limits, &b_limits);
		(*whole_cost)++;
	}
	*whole_cost += ft_tiny_sort(stack_a);
	*whole_cost += ft_push_back(stack_a, stack_b, &place, a_limits, &b_limits);
	*whole_cost += ft_end_move(*stack_a, a_limits);
}

unsigned int	ft_two_check(t_list *stack)
{
	if (stack->lower->number < stack->number)
	{
		ra(stack);
		return (1);
	}
	return (0);
}

void	ft_four_sort(t_list **stack_a, t_list **stack_b,
t_limit *a_limits, unsigned int *whole_cost)
{
	t_limit	b_limits;

	b_limits.size = 0;
	pb(stack_a, stack_b, a_limits, &b_limits);
	*whole_cost += 1;
	*whole_cost += ft_tiny_sort(stack_a);
	*whole_cost += ft_empty_stack(stack_a, stack_b, a_limits, &b_limits);
	*whole_cost += ft_end_move(*stack_a, a_limits);
}
//functions that sorts whole thing and returns the whole cost 

void	ft_sort(t_list **stack_a, t_list **stack_b, unsigned int *whole_cost)
{
	t_limit	a_limits;

	ft_duplicates(stack_a);
	a_limits.size = ft_count_args(*stack_a);
	if (ft_sorted(*stack_a))
		return ;
	if (a_limits.size == 2)
	{
		ra(*stack_a);
		whole_cost++;
		return ;
	}
	else if (a_limits.size == 3)
		*whole_cost = ft_tiny_sort(stack_a);
	else if (a_limits.size == 4)
		ft_four_sort(stack_a, stack_b, &a_limits, whole_cost);
	else
		ft_all_sort(stack_a, stack_b, &a_limits, whole_cost);
	return ;
}

int	main(int argc, char *argv[])
{
	unsigned int	whole_cost;
	t_list			*stack_a;
	t_list			*stack_b;

	whole_cost = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(0);
	ft_input_checker(argv);
	ft_set_stack(&stack_a, argv);
	ft_sort(&stack_a, &stack_b, &whole_cost);
	ft_free_nodes(&stack_a);
}
