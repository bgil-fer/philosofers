/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:17:14 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/09/26 14:01:40 by bgil-fer         ###   ########.fr       */
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
		ft_exit("Invalid number of arguments", NULL); //si este null funciona, mejor null para que no pete en el free porque aun no he inicializado esa estructura
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
			return (ft_exit("Error on arguments of type TIME", NULL), false);
		i++;
	}
	return (true);
}
//Cpmprobar si alguien se ha muerto, y si todos han comido el máximo de veces. 

void	*routine(void *sim)
{
	t_simulation *s;

	s = (t_simulation *) sim;
	//check si solo hay 1 philo- 
	while (!s->someone_died_bool)
	{
		eating(sim);
		spleeping(sim);
		thinking(sim);
	}
}

int	main(int argc, char **argv)
{
	t_simulation	sim;

	if (!check_args(argc, argv))
		return (1);
	if (!init_structures(&sim, argc, argv))
		return (ft_exit(NULL, &sim), 1);
	//liberar memoria de filosofos, forks, config. 
	return (0);
}
