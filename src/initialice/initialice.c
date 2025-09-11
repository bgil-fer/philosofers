/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:05:05 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/11 13:06:24 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_config(t_config **config, int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	(*config)->number_of_times_each_philo_must_eat = MAX_INT; //puedo hacer esto?
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1)
			(*config)->number_of_philo = num;
		else if (i == 2)
			(*config)->time_to_die = num;
		else if (i == 3)
			(*config)->time_to_eat = num;
		else if (i == 4)
			(*config)->time_to_sleep = num;
		else if (i == 5)
			(*config)->number_of_times_each_philo_must_eat = num;
		i++;
	}
}
