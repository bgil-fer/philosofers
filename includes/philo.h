/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:21:03 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/23 13:17:08 by bgil-fer         ###   ########.fr       */
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
bool	init_config(t_config **config, int argc, char **argv);
long	get_timestamp(void);
bool	init_simulation(t_simulation *sim, t_philo **philos);
bool	init_structures(t_simulation *sim, int argc, char **argv, t_philo **ph);

#endif