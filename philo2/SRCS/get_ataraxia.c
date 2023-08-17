/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ataraxia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:47:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/17 09:31:19 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*socrates_watch(void *arg)
{
	t_philo	*think;

	think = (t_philo *)arg;
	while (check_death(think) == 0)
	{
		pthread_mutex_lock(&think->lock);
		if (get_time() >= think->death_end && think->eating == 0
			&& think->data->waisted == 0)
		{
			display_status("DEAD", think);
			pthread_mutex_lock(&think->data->death_lock);
			think->data->waisted = 1;
			pthread_mutex_unlock(&think->data->death_lock);
			think->status = -1;
		}
		if (think->eat_count == think->data->round_nb)
		{
			pthread_mutex_lock(&think->data->lock);
			think->data->finish++;
			pthread_mutex_unlock(&think->data->lock);
		}
		pthread_mutex_unlock(&think->lock);
	}
	return ((void *)0);
}

void	*get_ataraxia(void *arg)
{
	t_philo	*think;

	think = (t_philo *)arg;
	think->death_end = think->data->death_time + get_time();
	if (pthread_create(&think->t1, NULL, &socrates_watch, (void *)think) != 0)
		return ((void *)1);
	while (check_death(think) == 0)
	{
		eat(think);
		display_status("THINK", think);
	}
	if (pthread_join(think->t1, NULL) != 0)
		return ((void *)1);
	return ((void *)0);
}
