/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:21:03 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/26 13:41:34 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h> // para tipo de dato bool
# include "structures.h"
# include <sys/time.h>
# include <limits.h>

int		ft_atoi(const char *nptr);
void	ft_exit(char *message, t_simulation *sim);
bool	init_config(t_simulation *sim, int argc, char **argv);
long	get_time(void);
bool	init_simulation(t_simulation *sim);
bool	init_philos(t_simulation *sim);
bool	init_structures(t_simulation *sim, int argc, char **argv);
void	eating(t_simulation *sim);
void	sleeping(t_simulation *sim);
void	thinking(t_simulation *sim);
bool	check_deaths(t_simulation *sim);

#endif