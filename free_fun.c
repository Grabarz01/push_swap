/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:12:19 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 10:36:00 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		free(args[i]);
	}
	free(args);
}

void	ft_free_nodes(t_list **stack)
{
	t_list	*tmp;

	while ((*stack)->lower)
	{
		tmp = (*stack)->lower;
		free(*stack);
		*stack = tmp;
	}
	free(*stack);
	*stack = NULL;
}
