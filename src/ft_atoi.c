/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:30:17 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/10 11:40:04 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		neg;
	int		res;

	neg = 0;
	i = 0;
	res = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	if (neg == 1)
		res = -res;
	return (res);
}
