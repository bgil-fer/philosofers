/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:39:20 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/26 14:00:42 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_simulation *sim)
{
	if (sim->ph->id % 2 == 0)
	{
		pthread_mutex_lock(sim->ph->left_fork);
		pthread_mutex_lock(sim->ph->right_fork);
	}
	else
	{
		pthread_mutex_lock(sim->ph->right_fork);
		pthread_mutex_lock(sim->ph->left_fork);
	}
	if (!check_deaths(sim))
		print(sim, 2);
}

static void	leave_forks(t_simulation *sim)
{
	pthread_mutex_unlock(sim->ph->left_fork);
	pthread_mutex_unlock(sim->ph->right_fork);
}

void	eating(t_simulation *sim)
{
	take_forks(sim);
	sim->ph->last_meal_time = get_time();
	if (!check_deaths(sim))
		print(sim, 3);
    sim->ph->times_have_eaten++;
    // comprobar con mutex si el filósofo ha comido tantas veces como number_of_times_each_philo_must_eat y para ello mutex. Si sí, all_eaten_count++
	wait(sim, sim->config->time_to_eat); // Tb función que cuente cuántass veces ha comido cada filósofo
	leave_forks(sim);
}

void	sleeping(t_simulation *sim)
{
	if (!check_deaths(sim))
		print(sim, 4);
	wait(sim, sim->config->time_to_sleep);
}

void	thinking(t_simulation *sim)
{
	if (!check_deaths(sim))
		print(sim, 5);
}
