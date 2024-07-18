/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:54:46 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 13:08:57 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_list	t_list;

struct s_list
{
	int		number;
	t_list	*upper;
	t_list	*lower;
	int		position;
};

typedef struct limits
{
	int	min;
	int	max;
	int	size;
}	t_limit;

typedef struct costs
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
	int	cost;
}	t_cost;

void			ft_sort(t_list **stack_a, t_list **stack_b,
					unsigned int *whole_cost);
void			ft_four_sort(t_list **stack_a, t_list **stack_b,
					t_limit *a_limits, unsigned int *whole_cost);
unsigned int	ft_two_check(t_list *stack);
void			ft_all_sort(t_list **stack_a, t_list **stack_b,
					t_limit *a_limits, unsigned int *whole_cost);
unsigned int	ft_empty_stack(t_list **stack_a, t_list **stack_b,
					t_limit *a_limits, t_limit *b_limits);
unsigned int	ft_push_back(t_list **stack_a, t_list **stack_b,
					t_cost *place, t_limit *a_limits, t_limit *b_limits);
unsigned int	ft_empty_stack(t_list **stack_a, t_list **stack_b,
					t_limit *a_limits, t_limit *b_limits);
unsigned int	ft_place_in_a(t_list **stack_a, t_list **stack_b,
					int value, t_limit *a_limits);
unsigned int	ft_tiny_sort(t_list **stack_a);
void			ft_top_node(t_list **stack_to_change, t_list **stack_to_free,
					int value);
unsigned int	ft_rot_stack_b(t_list *stack, t_limit *limits, t_cost *place);
void			ft_replace(t_list **stack_a, t_list **stack_b, t_cost *place);
unsigned int	ft_end_move(t_list *stack_a, t_limit *a_limts);
void			ft_change_limits_given(t_limit *limits, int value);
void			ft_change_limits_taken(t_list *stack, t_limit *limits);
void			ft_set_positions(t_list *stack_a, t_list *stack_b,
					t_limit *a_limits, t_limit *b_limits);
void			pb(t_list **stack_a, t_list **stack_b,
					t_limit *a_limits, t_limit *b_limits);
void			pa(t_list **stack_a, t_list **stack_b,
					t_limit *a_limits, t_limit *b_limits);
void			rrb(t_list *stack_b);
void			rra(t_list *stack_a);
void			rrr(t_list *stack_a, t_list *stack_b);
void			rb(t_list *stack_b);
void			ra(t_list *stack_a);
void			rr(t_list *stack_a, t_list *stack_b);
void			sb(t_list *stack);
void			sa(t_list *stack);
void			ft_rev_rotate(t_list *stack);
void			ft_rotate(t_list *stack);
void			ft_swap(t_list *stack);
int				ft_get_one_bigger(t_list *stack, int value);
int				ft_get_value(t_list *stack, int pos);
int				ft_get_pos(t_list *stack, int value);
int				ft_get_one_smaller(t_list *stack, int value);
void			ft_cost_cal(t_list *stack_a, t_list *stack_b, t_limit *a_limits,
					t_limit *b_limits, t_cost *place);
void			ft_set_costs(t_cost *price);
void			ft_cost(int pos, int final_pos, t_limit *a_limits,
					t_limit *b_limits, t_cost *place);
void			ft_optimalization(t_cost *tmp_price);
int				ft_count_optim(int *a, int *b);
void			ft_free_split(char **args);
void			ft_free_nodes(t_list **stack);
int				ft_sorted(t_list *stack);
int				ft_get_min(t_list *stack);
int				ft_get_max(t_list *stack);
void			ft_input_checker(char **strs);
int				ft_string_checker(char *str);
char			*ft_arg_checker(char *arg);
void			ft_duplicates(t_list **stack_a);
int				ft_count_args(t_list *stack_a);
void			ft_set_stack(t_list **stack_a, char **str);
void			ft_insert_arg(t_list **stack_a, char *arg);
void			ft_add_node(t_list **stack_a, int a);
int				ft_int_atoi(char *str, unsigned int *a);
#endif