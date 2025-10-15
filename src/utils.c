/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:59:20 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/10/15 12:19:29 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print(t_philo *ph, int m)
{
	long long	time;

	pthread_mutex_lock(&ph->sim->print_mutex);
	time = get_time() - ph->start_time;
	if (m == 1)
		printf("[%lld] %zu has died\n", time, ph->id);
	else if (m == 2)
		printf("[%lld] %zu has taken a fork\n", time, ph->id);
	else if (m == 3)
		printf("[%lld] %zu is eating\n", time, ph->id);
	else if (m == 4)
		printf("[%lld] %zu is sleeping\n", time, ph->id);
	else if (m == 5)
		printf("[%lld] %zu is thinking\n", time, ph->id);
	pthread_mutex_unlock(&ph->sim->print_mutex);
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

void	wait(t_philo *ph, int time)
{
	long	now;

	now = get_time();
	while (!check_deaths(ph->sim) && (get_time() - now) < time)
		usleep(50);
}
