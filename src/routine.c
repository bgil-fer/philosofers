/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:39:20 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/10/08 18:34:59 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		pthread_mutex_lock(ph->left_fork);
		if (!check_deaths(ph->sim))
			print(ph, 2);
		pthread_mutex_lock(ph->right_fork);
		if (!check_deaths(ph->sim))
			print(ph, 2);
	}
	else
	{
		pthread_mutex_lock(ph->right_fork);
		if (!check_deaths(ph->sim))
			print(ph, 2);
		pthread_mutex_lock(ph->left_fork);
		if (!check_deaths(ph->sim))
			print(ph, 2);
	}
}

static void	leave_forks(t_philo *ph)
{
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
}

void	eating(t_philo *ph)
{
	take_forks(ph);
	ph->last_meal_time = get_time();
	if (!check_deaths(ph->sim))
		print(ph, 3);
	ph->times_have_eaten++;
	if (ph->times_have_eaten == ph->sim->config->number_of_times_to_eat)
	{
		pthread_mutex_lock(&ph->sim->all_eaten);
		ph->sim->all_eaten_count++;
		pthread_mutex_unlock(&ph->sim->all_eaten);
	}
	wait(ph, ph->sim->config->time_to_eat);
	leave_forks(ph);
}

void	sleeping(t_philo *ph)
{
	if (!check_deaths(ph->sim))
		print(ph, 4);
	wait(ph, ph->sim->config->time_to_sleep);
}

void	thinking(t_philo *ph)
{
	if (!check_deaths(ph->sim))
		print(ph, 5);
}
