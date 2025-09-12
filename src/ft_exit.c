/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:39:03 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/12 13:41:41 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutexes(t_simulation *sim)
{
	int	i;

	i = 0;
	if (sim->forks && sim->config && sim->config->number_of_philo)
	{
		while (i < sim->config->number_of_philo)
		{
			pthread_mutex_destroy(&sim->forks[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&sim->print_mutex); //añadir bandera de inicialización en estructura :(
	pthread_mutex_destroy(&sim->state_control_mutex);//añadir bandera de inicialización en estructura :( también para los forks. 
}

void	ft_exit(char *message, t_simulation *sim)
{
	if (message)
		printf("Error: %s\n", message);
	if (sim)
	{
		if (sim->config)
		free(sim->config);
		if (sim->philos)
		free(sim->philos);
		destroy_mutexes(sim);
		if (sim->forks)
			free(sim->forks);
	} 
}
