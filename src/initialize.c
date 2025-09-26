/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:05:05 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/26 13:59:10 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_config(t_simulation *sim, int argc, char **argv)
{
	int			i;
	int			num;

	i = 1;
	if (!(sim->config = malloc(sizeof(t_config))))
    	return (false);
	(sim->config)->number_of_times_each_philo_must_eat = INT_MAX; //puedo hacer esto? uso -1?
	while (i < argc)
	{
		if (num = ft_atoi(argv[i]))
			return (false);
		if (i == 1)
			(sim->config)->numb_philo = num;
		else if (i == 2)
			(sim->config)->time_to_die = num;
		else if (i == 3)
			(sim->config)->time_to_eat = num;
		else if (i == 4)
			(sim->config)->time_to_sleep = num;
		else if (i == 5)
			(sim->config)->number_of_times_each_philo_must_eat = num;
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
	while (i < sim->config->numb_philo)
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

bool	init_simulation(t_simulation *sim)
{
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * sim->config->numb_philo);
	if (!philos)
		return (ft_exit("Memory allocation", &sim), false);
	sim->ph = philos;
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->config->numb_philo);
	if (!sim->forks)
		return (ft_exit("Memory allocation", &sim), false);
	init_mutexes(&sim);
	sim->someone_died_init = false;
	if (pthread_mutex_init(&sim->someone_died, NULL))
		return (ft_exit("Initializing mutexes", sim), false);
	else
	{
		sim->someone_died_init = true;
		sim->someone_died_bool = false;
	}
	if (pthread_mutex_init(&sim->all_eaten, NULL))
		return (ft_exit("Initializing mutexes", sim), false);
	else
	{
		sim->all_eaten_init = true;
		sim->all_eaten_count = 0;
	}
	sim->start_time = get_time(); //probarr
	return (true);
}

bool	init_philos(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->config->numb_philo)
	{
		sim->ph[i].id = i + 1;
		sim->ph[i].times_have_eaten = 0;
		sim->ph[i].last_meal_time = get_time();
		sim->ph[i].left_fork = &sim->forks[i];
		sim->ph[i].right_fork = &sim->forks[(i + 1) % sim->config->numb_philo];
		if (pthread_create(&sim->ph[i].thread, NULL, routine(), sim))
			return (ft_exit("Creating a thread", sim), false);
		i++;
	}
	return (true);
}

bool	init_structures(t_simulation *sim, int argc, char **argv)
{
	if (!init_config(sim, argc, argv))
		return (false);
	if (!init_simulation(sim))
		return (false);
	if (!init_philos(sim))
		return (false);
	return (true);
}
