/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:28:33 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/10/08 18:49:23 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_philos_death(t_simulation *sim)
{
	int	i;
	
	i = 0;
	while (i < sim->config->numb_philo)
	{
		if ((get_time() - sim->ph[i].last_meal_time) > sim->config->time_to_die)
		{
			pthread_mutex_lock(&sim->someone_died);
			sim->someone_died_bool = true;
			pthread_mutex_unlock(&sim->someone_died);
			print(&sim->ph[i], 1); 
			return (true);
		}
		i++;
	}
	return (false);
}

void	*init_guard(void *arg)
{
	t_simulation	*sim;

	sim = (t_simulation *) arg;
	while (1)
	{
		if (check_philos_death(sim))
			return (NULL);
		pthread_mutex_lock(&sim->all_eaten);
		if (sim->config->number_of_times_to_eat != -1 && sim->all_eaten_count >= sim->config->numb_philo)
		{
			pthread_mutex_lock(&sim->someone_died);
			sim->someone_died_bool = true;
			pthread_mutex_unlock(&sim->someone_died);
			pthread_mutex_unlock(&sim->all_eaten);
			return (NULL);
		}
		pthread_mutex_unlock(&sim->all_eaten);
	}
	return (NULL);
}
