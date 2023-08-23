/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ataraxia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:47:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/23 21:35:09 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_watch(void *arg)
{
	t_philo	*think;

	think = (t_philo *)arg;
//	usleep(1000);
//	pthread_mutex_lock(&think->data->release);
//	pthread_mutex_unlock(&think->data->release);
	while (1)
	{
		if (check_death(think) == 1 || check_finish(think) == 1)
			break ;
	}
	return ((void *)0);
}

static int	times_up(t_philo *think)	
{
	pthread_mutex_lock(&think->lock);
	if (get_time() >= think->death_end && check_death(think) == 0)
	{
		write_death(think);
		pthread_mutex_unlock(&think->lock);
		return (-1);
	}
	if (think->data->round_nb > 0 &&
		think->eat_count >= think->data->round_nb)
		write_finish(think);
	pthread_mutex_unlock(&think->lock);
	return (0);
}

void	*get_ataraxia(void *arg)
{
	t_philo		*think;

	think = (t_philo *)arg;
//	pthread_mutex_lock(&think->data->release);
//	pthread_mutex_unlock(&think->data->release);
	think->death_end = think->data->death_time + get_time();
	while (1)
	{
		if (check_death(think) == 1 || check_finish(think) == 1
			|| times_up(think) == -1)
			break ;
		if (chop_trylock(think) == 1)
		{
			eat(think);
			display_status(THINK, think);
			usleep(1000);
		}
	}
	return ((void *)0);
}
