/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:30:17 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/10/15 15:03:59 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_if_characters(const char *nptr)
{
	int		i;
	bool	charac;

	i = 0;
	charac = false;
	while (nptr[i])
	{
		if (nptr[i] < 48 || nptr[i] > 57)
			charac = true;
		i++;
	}
	return (charac);
}

static int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *n)
{
	size_t	i;
	int		neg;
	int		res;

	neg = 0;
	i = 0;
	res = 0;
	while (n[i] && ft_isspace(n[i]))
		i++;
	if (n[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (n[i] == '+')
		i++;
	while (n[i] && (n[i] >= 48 && n[i] <= 57) && !check_if_characters(&n[i]))
	{
		res = res * 10 + (n[i] - 48);
		i++;
	}
	if (neg == 1)
		res = -res;
	return (res);
}
