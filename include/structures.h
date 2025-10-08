/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:24:37 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/10/08 17:41:04 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_config
{
	int		numb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_to_eat;
}			t_config;

typedef struct s_philo
{
	size_t				id;
	int					times_have_eaten;
	long				start_time;
	long				last_meal_time;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_simulation	*sim;
}					t_philo;

typedef struct s_simulation
{
	t_config		*config;
	t_philo			*ph;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	bool			forks_init;
	pthread_mutex_t	print_mutex;
	bool			print_mutex_init;
	pthread_mutex_t	someone_died;
	bool			someone_died_bool;
	bool			someone_died_init;
	pthread_mutex_t	all_eaten;
	bool			all_eaten_init;
	int				all_eaten_count;
	//long			start_time;
}					t_simulation;

#endif 