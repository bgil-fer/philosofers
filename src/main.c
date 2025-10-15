/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:17:14 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/10/15 14:48:45 by bgil-fer         ###   ########.fr       */
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
		ft_exit("Invalid number of arguments", NULL);
		return (false);
	}
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1 && (num < 1 || num > INT_MAX))
			return (ft_exit("Invalid number of philosofers", NULL), false);
		else if (i == 5 && (num < 1 || num > INT_MAX))
			return (ft_exit("Invalid number_of_times_must_eat", NULL), false);
		else if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
			return (ft_exit("on arguments of type TIME", NULL), false);
		i++;
	}
	return (true);
}

void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	if (ph->sim->config->n_philo == 1)
	{
		print(ph, 2);
		ph->sim->someone_died_bool = true;
		return (NULL);
	}
	while (!ph->sim->someone_died_bool)
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
		usleep(2000);
	}
	return (NULL);
}

static void	join_threads(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->config->n_philo)
	{
		pthread_join(sim->ph[i].thread, NULL);
		i++;
	}
	pthread_join(sim->monitor, NULL);
}

int	main(int argc, char **argv)
{
	t_simulation	sim;

	if (!check_args(argc, argv))
		return (1);
	if (!init_structures(&sim, argc, argv))
		return (ft_exit(NULL, &sim), 1);
	join_threads(&sim);
	ft_exit(NULL, &sim);
	return (0);
}
