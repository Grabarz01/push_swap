/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:12:19 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 16:18:00 by fgrabows         ###   ########.fr       */
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

	if(!*stack)
		return;
	while ((*stack)->lower)
	{
		tmp = (*stack)->lower;
		free(*stack);
		*stack = tmp;
	}
	free(*stack);
	*stack = NULL;
}
