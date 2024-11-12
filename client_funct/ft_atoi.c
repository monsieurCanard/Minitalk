/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:30:11 by marvin            #+#    #+#             */
/*   Updated: 2023/10/18 11:30:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static int	ft_whitespace(char c)
{
	if (c == '\n' || c == '\r' || c == '\t' || c == '\v'
		|| c == '\f' || c == ' ')
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	conv;
	int	sign;

	conv = 0;
	i = 0;
	sign = 1;
	while (ft_whitespace(((char *)str)[i]) == 0)
		i++;
	if (((char *)str)[i] == '-' || ((char *)str)[i] == '+' )
	{
		if (((char *)str)[i] == '-')
			sign = -sign;
		i++;
	}
	while (((char *)str)[i] <= '9' && ((char *)str)[i] >= '0')
	{
		conv = (conv * 10) + ((char *)str)[i] - 48;
		i++;
	}
	return (conv * sign);
}
