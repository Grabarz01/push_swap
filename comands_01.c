/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:26:38 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 20:09:58 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list *stack)
{
	ft_swap(stack);
	write(1, "sb\n", 3);
}

void	sa(t_list *stack)
{
	ft_swap(stack);
	write(1, "sa\n", 3);
}

void	rb(t_list *stack_b)
{
	write(1, "rb\n", 3);
	ft_rotate(stack_b);
}

void	ra(t_list *stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	write(1, "rr\n", 3);
	ft_rotate(stack_b);
	ft_rotate(stack_a);
}
