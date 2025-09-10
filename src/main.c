/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:17:14 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/10 13:29:18 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int argc, char **argv, t_config **config)
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
			print_error_message("Invalid number_of_times_each_philo_must_eat", 1);
		else if (i != 1 && i != 5 && (num < 1 || num > MAX_INT))
			print_error_message("Error on arguments of type TIME", 1);
		if (i == 1)
			(*config)->number_of_philosophers = num;
		else if (i == 5)
			(*config)->number_of_times_each_philo_must_eat = num;
		else if (i == 2)
			(*config)->time_to_die = num;
		else if (i == 3)
			(*config)->time_to_eat = num;
		else
			(*config)->time_to_sleep = num;
		i++;
	}
}

void	init_structures(t_config **config, t_philo **philos)
{
	
}

int	main(int argc, char **argv)
{
	t_config	*config;
	t_philo		*philos;

	check_args(argc, argv, &config);
	init_structures(&config, &philos);
	return(0);
}
