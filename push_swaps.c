/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:33:38 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 08:15:55 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"









//implementation of program functons 





//atoi
int		ft_atoi(const char *str)
{

	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' ||
			str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
} 
//everything for split
int ft_strlen(char const *str)
{

	int i;
	if(!str)
		return(0);
	i = 0;
	while(str[i])
		i++;
	return(i);
}

static int	count_words(const char *str, char c)
{

	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{

	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

// end of split



























/*
- tak care of more than int max and less than int min
*/

/*
input checkers.c:
xvoid ft_input_checker(char **strs)
xint ft_string_checker(char* str)
xchar* ft_arg_checker(char *arg)
xvoid ft_duplicates(t_list **stack_a)
xint ft_count_args(t_list* stack_a)


stack_builders.c:
xvoid ft_set_stack(t_list** stack_a, char **str)
xvoid ft_insert_arg(t_list** stack_a, char *arg)
xvoid ft_add_node(t_list** stack_a, int a)
xvoid ft_top_node(t_list **stack_to_change, t_list** stack_to_free, int value)


main.c:
xmain 
xvoid ft_sort(t_list **stack_a, t_list **stack_b,unsigned int *whole_cost)
xvoid ft_four_sort(t_list** stack_a,t_list** stack_b, limit* a_limits, unsigned int *whole_cost)
xunsigned int ft_two_check(t_list *stack)
xvoid ft_all_sort(t_list **stack_a, t_list**stack_b, limit* a_limits, unsigned int* whole_cost)

sorting:
xunsigned int ft_push_back(t_list** stack_a, t_list** stack_b, cost *place,limit* a_limits, limit* b_limits)
xunsigned int ft_empty_stack(t_list** stack_a, t_list** stack_b, limit *a_limits, limit *b_limits)
xunsigned int ft_place_in_a(t_list** stack_a, t_list ** stack_b, int value, limit *a_limits)
xunsigned int ft_tiny_sort(t_list **stack_a)
xunsigned int ft_rot_stack_b(t_list* stack, limit* limits, cost *place)

stack_mangement:
xvoid ft_replace(t_list ** stack_a ,t_list** stack_b, cost *place)
xunsigned int ft_end_move(t_list* stack_a, limit *a_limts)
xvoid ft_change_limits_given(limit* limits, int value)
xvoid ft_change_limits_taken(t_list* stack, limit* limits)
xvoid ft_set_positions(t_list *stack_a, t_list* stack_b, limit* a_limits, limit* b_limits)//do tests for it


comands:
xvoid pb(t_list** stack_a, t_list** stack_b, limit *a_limits, limit* b_limits)
xvoid pa(t_list** stack_a, t_list** stack_b, limit *a_limits, limit* b_limits)
xvoid rrb(t_list *stack_b)
xvoid rra(t_list *stack_a)
xvoid rrb(t_list *stack_b)

comands_2:
xvoid rb(t_list *stack_b)
xvoid ra(t_list *stack_a)
xvoid rr(t_list* stack_a, t_list* stack_b)
xvoid sb(t_list* stack)
xvoid sa(t_list* stack)

comands_exe
xvoid ft_rev_rotate(t_list *stack)
xvoid ft_rotate(t_list *stack)
xvoid ft_swap(t_list* stack)

find_in_stack:
xint ft_get_one_bigger(t_list *stack, int value)
xint ft_get_value(t_list *stack, int pos)
xint ft_get_pos(t_list *stack, int value)
xint ft_get_one_smaller(t_list *stack, int value)


cost_cal
xvoid ft_cost_cal(t_list *stack_a, t_list *stack_b, limit *a_limits, limit *b_limits, cost* place)
xvoid ft_set_costs(cost *price)
xvoid ft_cost(int pos, int final_pos, limit* a_limits, limit* b_limits, cost* place)
xvoid ft_optimalization(cost* tmp_price)
xint ft_count_optim(int* a, int* b)

free_fun
xvoid ft_free_split(char **args)
xvoid ft_free_nodes(t_list **stack)

stack_checkers
xint ft_sorted(t_list *stack)
xint ft_get_min(t_list* stack)
xint ft_get_max(t_list* stack)

*/