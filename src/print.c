/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:39:03 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/10 12:14:39 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error_message(char *message, int signal)
{
	if (message)
		printf("Error: %s\n", message);
	exit(signal); // signaaal???? --> nº que me devuelve como error.
}

