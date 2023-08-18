/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ataraxia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:47:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/18 10:38:13 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*death_watch(void *arg)
{
	t_philo	*think;

	think = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&think->lock);
		if (get_time() >= think->death_end && check_eating(think) == 0
			&& check_death(think) == 0)
		{
			write_death(think);
			pthread_mutex_unlock(&think->lock);
			return ((void *)0);
		}
		if (think->eat_count == think->data->round_nb)
		{
			write_finish(think);
			pthread_mutex_unlock(&think->lock);
			return ((void *)0);
		}
		pthread_mutex_unlock(&think->lock);
		if (check_death(think) == 1)
			break ;
	}
	return ((void *)0);
}

void	*get_ataraxia(void *arg)
{
	t_philo	*think;

	think = (t_philo *)arg;
	think->death_end = think->data->death_time + get_time();
	if (pthread_create(&think->t1, NULL, &death_watch, (void *)think) != 0)
		return ((void *)1);
	while (1)
	{
		if (check_death(think) == 1)
			break ;
		eat(think);
		display_status("THINK", think);
	}
	if (pthread_join(think->t1, NULL) != 0)
		return ((void *)1);
	return ((void *)0);
}
