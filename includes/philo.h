/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:21:03 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/11 14:00:23 by bgil-fer         ###   ########.fr       */
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

# define MAX_INT 2147483647

int		ft_atoi(const char *nptr);
void	print_error_message(char *message, int signal);
void	init_config(t_config **config, int argc, char **argv);
long	get_timestamp(void);
void	init_structures(t_simulation *sim, int argc, char **argv);

#endif