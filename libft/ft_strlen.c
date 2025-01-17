/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:36:05 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 12:42:58 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if(!s)
		return(0);
	while (s[i])
	{
		i++;
	}
	return (i);
}
/*
10
11
12
19
27
28
36
*/