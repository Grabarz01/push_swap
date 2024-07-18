/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:46:52 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 21:53:04 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_all_sort(t_list **stack_a, t_list **stack_b, t_limit *a_limits)
{
	t_limit	b_limits;

	b_limits.size = 0;
	pb(stack_a, stack_b, a_limits, &b_limits);
	pb(stack_a, stack_b, a_limits, &b_limits);
	while (a_limits->size > 3)
	{
		ft_cost_cal(*stack_a, *stack_b, a_limits, &b_limits);
		pb(stack_a, stack_b, a_limits, &b_limits);
	}
	ft_tiny_sort(stack_a, ft_get_value(*stack_a,2));
	ft_push_back(stack_a, stack_b, a_limits, &b_limits);
	ft_end_move(*stack_a, a_limits);
}

void	ft_four_sort(t_list **stack_a, t_list **stack_b,
t_limit *a_limits)
{
	t_limit	b_limits;

	b_limits.size = 0;
	pb(stack_a, stack_b, a_limits, &b_limits);
	ft_tiny_sort(stack_a, ft_get_value(*stack_a,2));
	ft_empty_stack(stack_a, stack_b, a_limits, &b_limits);
	ft_end_move(*stack_a, a_limits);
}
//functions that sorts whole thing and returns the whole cost 

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	t_limit	a_limits;

	ft_duplicates(stack_a);
	a_limits.size = ft_count_args(*stack_a);
	if (ft_sorted(*stack_a))
		return ;
	if (a_limits.size == 2)
		ra(*stack_a);
	else if (a_limits.size == 3)
		ft_tiny_sort(stack_a, ft_get_value(*stack_a,2));
	else if (a_limits.size == 4)
		ft_four_sort(stack_a, stack_b, &a_limits);
	else
		ft_all_sort(stack_a, stack_b, &a_limits);
	return ;
}

int	main(int argc, char *argv[])
{
	t_list			*stack_a;
	t_list			*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(0);
	ft_input_checker(argv);
	ft_set_stack(&stack_a, argv, 0);
	ft_sort(&stack_a, &stack_b);
	ft_free_nodes(&stack_a);
}
