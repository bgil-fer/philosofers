/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:17:14 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/11 14:01:23 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	if (argc < 5 || argc > 6)
		print_error_message("Invalid number of arguments", 1);
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1 && (num < 1 || num > MAX_INT))
			print_error_message("Invalid number of philosofers", 1);
		else if (i == 5 && (num < 0 || num > MAX_INT))
			print_error_message("Invalid number_of_times_philo_must_eat", 1);
		else if (i != 1 && i != 5 && (num < 1 || num > MAX_INT))
			print_error_message("Error on arguments of type TIME", 1);
	}
}

void	create_threads(t_simulation *sim)
{
	int	i;

	i = 1;
	while (i < sim->config->number_of_philosophers)
	{
		pthread_create();
		i++;
	}
}

/*
Cómo usar gettimeofday
void init_simulation(t_simulation *sim, t_philo **philos)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    sim->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;

    // ... resto de la inicialización
}
*/

void	init_simulation(t_simulation *sim, t_philo **philos)
{
	struct timeval	tv; //es legal?

	*philos = malloc(sizeof(t_philo) * sim->config.number_of_philo);
	if (!(*philos))
		print_error_message("Error while reserving memory", 1);
	sim->philos = *philos;
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->config.number_of_philo);
	if (!sim->forks)
		print_error_message("Error while reserving memory", 1);
	// print_mutex;
	// pthread_mutex_t	state_control_mutex;
	// bool			someone_died;
	sim->start_time = get_timestamp(); //probarr
}

void	init_structures(t_simulation *sim, int argc, char **argv, t_philo **ph)
{
	init_config(&(sim->config), argc, argv);
	init_simulation(sim, ph);
	init_philos();
}

int	main(int argc, char **argv)
{
	t_simulation	sim;
	t_philo			*philos;

	check_args(argc, argv);
	init_structures(&sim, argc, argv, &philos);
	//create_threads();
	//liberar memoria de filosofos. 
	return (0);
}
