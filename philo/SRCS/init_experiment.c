/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_experiment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:18:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/24 18:18:54 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	init_thinkers(t_philo *cond, ac)
{
	int	i;

	cond->thinker = malloc((ac - 1) * sizeof(t_thinker));
	if (!cond->thinker)
		return (-1);
	i = 0;
	while (i < cond->fork_nb)
	{
		cond->thinker[i]->data = cond;
		cond->thinker[i]->id = i + 1;
		cond->thinker[i]->time_to_die = cond->die_time;
		cond->thinker[i]->eating = 0;
		cond->thinker[i]->status = 0;
		cond->thinker[i]->eat_lock = 0;
	}
	return (1);
}

static int	forks_init(t_philo *cond)
{
	int	i;

	i = 0;
	cond->forks = malloc(fork_nb * sizeof(pthread_mutex_t));
	if (!cond->forks)
		return (clear_error("ERR: FORKS ALLOC ERROR\n", cond));
	while (i < cond->fork_nb)
	{
		pthread_mutex_init(&cond->forks[i], NULL)
		i++;
	}
	cond->thinker[0].l_fork = &cond->forks[0];
	cond->thinker[0].r_fork = &cond->forks[cond->fork_nb - 1];
	i = 1;
	while (i < cond->fork_nb)
	{
		cond->thinker[i].l_fork = &cond->forks[i];
		cond->thinker[i].r_fork = &cond->forks[i - 1];
	}
	return (1);
}

static void	init_conditions(t_philo *cond, char **av)
{
	cond->fork_nb = ft_atoi(av[1]);
	cond->die_time = (uint64_t)ft_atoi(av[2]);
	cond->eat_time = (uint64_t)ft_atoi(av[3]);
	cond->sleep_time = (uint64_t)ft_atoi(av[4]);
	if (av[5])
	{
		cond->round_nb = ft_atoi(av[5]);
		if (cond->round_nb < 1)
			return (free(cond), NULL);
	}
	else
		cond->round_nb = -1;
	if (cond->die_time < 0 || cond->fork_nb < 1 || cond->sleep_time < 0)
		return (clear_error("ERR: BAD VALUES", cond));
}

int	init_experiment(t_philo *cond, char **av, int ac)
{
	init_conditions(cond, av);
	if (init_thinkers(cond, ac) == -1)
		return (clear_error("ERR: THINKER STRUCT ALLOC FAILED\n", cond));
	if (forks_init() == -1)
		return (clear_error("ERR: FORKS INIT FAILED\n"), cond);
	return (1);
}
