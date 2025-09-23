/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:05:05 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/23 13:22:51 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_config(t_config **config, int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	*config = malloc(sizeof(t_config));
	if (!*config)
    	return (false);
	(*config)->number_of_times_each_philo_must_eat = INT_MAX; //puedo hacer esto? uso -1?
	while (i < argc)
	{
		if (!(num = ft_atoi(argv[i]))) //Arreglar esto porque si em meten un 0 dará error. 
			return (false);
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
	return (true);
}

static bool	init_mutexes(t_simulation *sim)
{
	int	i;

	i = 0;
	sim->print_mutex_init = false;
	sim->state_control_mutex_init = false;
	sim->forks_init = false;
	while (i < sim->config->number_of_philo)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL))
			return (ft_exit("Initializing mutexes", sim), false);
		i++;
	}
	sim->forks_init = true;
	if (pthread_mutex_init(&sim->print_mutex, NULL))
		return (ft_exit("Initializing mutexes", sim), false);
	else
		sim->print_mutex_init = true; 
	if (pthread_mutex_init(&sim->state_control_mutex, NULL))
		return (ft_exit("Initializing mutexes", sim), false);
	else
		sim->state_control_mutex_init = true;
	return (true);
}

bool	init_simulation(t_simulation *sim, t_philo **philos)
{
	*philos = malloc(sizeof(t_philo) * sim->config->number_of_philo);
	if (!(*philos))
		return (ft_exit("Memory allocation", &sim), false);
	sim->philos = *philos;
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->config->number_of_philo);
	if (!sim->forks)
		return (ft_exit("Memory allocation", &sim), false);
	init_mutexes(&sim);
	sim->someone_died = false;
	sim->start_time = get_timestamp(); //probarr
	return (true);
}
