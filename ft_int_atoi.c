/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:45:24 by fgrabows          #+#    #+#             */
/*   Updated: 2024/07/18 13:11:39 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_minus(char s)
{
	if(s == '-')
		return (-1);
	return(1);
}
int ft_int_atoi(char *str , unsigned int *a)
{
	int minus;
	
	*a = 0;
	while (*str && *str == ' ')
		str++;
	if(*str == '-' || *str == '+')
	{
		minus = ft_minus(*str);
		str++;
	}
	else
		minus = 1;
	while(*str && (*str >= '0' && *str <= '9'))
	{
		*a = *a * 10 + (*str - '0');
		if(*a > (long)INT_MAX + 1)
			return(0);
		else if (*a > INT_MAX && minus == -1)
			return(0);
		str++;
	}
	return(minus);
}
