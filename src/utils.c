/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:59:20 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/26 13:50:31 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print(t_simulation *sim, int m)
{
	long	time;

	time = get_time();
	pthread_mutex_lock(&sim->print_mutex);
	if (m == 1)
		printf("[%zu] %i has died\n", time, sim->ph->id);
	else if (m == 2)
		printf("[%zu] %i has taken a fork\n", time, sim->ph->id);
	else if (m == 3)
		printf("[%zu] %i is eating\n", time, sim->ph->id);
	else if (m == 4)
		printf("[%zu] %i is sleeping\n", time, sim->ph->id);
	else if (m == 5)
		printf("[%zu] %i is thinking\n", time, sim->ph->id);
	pthread_mutex_unlock(&sim->print_mutex);
}

bool	check_deaths(t_simulation *sim)
{
	bool	death;
	pthread_mutex_lock(&sim->someone_died);
	if (sim->someone_died_bool == false)
		death = false;
	else
		death = true;
	pthread_mutex_unlock(&sim->someone_died);
	return (death);
}

void	wait(t_simulation *sim, int time)
{
	long	now;
	
	now = get_time();
	while(!check_deaths && (now - sim->start_time) < time)
		usleep(50);
}
