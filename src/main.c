/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:17:14 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/23 13:58:18 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_args(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		ft_exit("Invalid number of arguments", NULL); //si este null funciona, mejor null para que no pete en el free porque aun no he inicializado esa estructura
		return (false);
	}
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1 && (num < 1 || num > INT_MAX))
			return (ft_exit("Invalid number of philosofers", NULL), false);
		else if (i == 5 && (num < 0 || num > INT_MAX))
			return (ft_exit("Invalid number_of_times_must_eat", NULL), false);
		else if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
			return (ft_exit("Error on arguments of type TIME", NULL), false);
		i++;
	}
	return (true);
}

/*
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
*/

bool	init_philos(t_simulation *sim, t_philo **ph)
{
	int	i;

	i = 0;
	while (i < sim->config->number_of_philo)
	{
		(*ph)[i]->id = i + 1;
		ph[i]->times_have_eaten = 0;
		ph[i]->last_meal_time = sim->start_time;
		if (pthread_create(ph[i]->thread, NULL, routine(), sim)) // crear función para la rutina
			return (ft_exit("Creating a thread", sim), false);
		//faltan los forks
		i++;
	}
	sim->philos = &ph; //falta geestionar bien esto :)
	return (true);
}

bool	init_structures(t_simulation *sim, int argc, char **argv, t_philo **ph)
{
	if (!init_config(&(sim->config), argc, argv))
		return (false);
	if (!init_simulation(sim, ph))
		return (false);
	if (!init_philos(sim, ph))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_simulation	sim;
	t_philo			*philos;

	if (!check_args(argc, argv))
		return (1);
	if (!init_structures(&sim, argc, argv, &philos))
		return (ft_exit(NULL, &sim), 1);
	//create_threads();
	//liberar memoria de filosofos, forks, config. 
	return (0);
}
