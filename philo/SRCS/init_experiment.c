/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_experiment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:18:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/12 15:18:07 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo	*init_experiment(char **av)
{
	t_philo	*cond;

	cond = malloc(1, sizeof(t_philo));
	if (! cond)
		return (NULL);
	cond->thinker = malloc(ft_atoi(av[1]) * sizeof(pthread_t));
	if (!cond->thinker)
		return (free(cond), NULL);
	cond->fork_nb = ft_atoi(av[1]);
	cond->die_time = ft_atoi(av[2]);
	cond->eat->time = ft_atoi(av[3]);
	cond->sleep_time = ft_atoi(av[4]);
	if (av[5])
	{
		cond->round_nb = ft_atoi(av[5]);
		if (cond->round_nb < 1)
			return (free(cond), NULL);
	}
	else
		cond->round_nb = -1;
}
