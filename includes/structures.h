/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:24:37 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/11 13:53:34 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "philo.h"

typedef struct s_config
{
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philo_must_eat;
	bool	must_eat_enabled; //????
}			t_config;

typedef struct s_philo
{
	size_t			id;
	size_t			times_have_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;//no sé si esto me convence
	pthread_mutex_t	*right_fork;

}	t_philo;

typedef struct s_simulation
{
	t_config		config;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_control_mutex;
	bool			someone_died;
	long			start_time;
}					t_simulation;

#endif 