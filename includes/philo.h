/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:21:03 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/10 13:30:10 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_INT 2147483647

typedef struct s_config
{
	int	number_of_philosophers;
	int	time_to_die;
	int time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philo_must_eat;
}	t_config;

typedef struct s_philo
{
	size_t	id;
	size_t	times_have_eaten;

}	t_philo;

int		ft_atoi(const char *nptr);
void	print_error_message(char *message, int signal);
void	init_structures(t_config **config, t_philo **philos);



#endif