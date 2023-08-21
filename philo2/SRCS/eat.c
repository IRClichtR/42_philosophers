/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:46:05 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/21 17:17:13 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	unlock_chopsticks(t_philo *think)
{
	pthread_mutex_unlock(think->l_chop);
	pthread_mutex_unlock(think->r_chop);
	search_for_truth(think);
}

static void	take_chopsticks(t_philo *think)
{
	if (think->think_id < think->data->think_nb)
	{
		pthread_mutex_lock(think->r_chop);
		display_status(FORK, think);
		pthread_mutex_lock(think->l_chop);
		display_status(FORK, think);
	}
	else
	{
		pthread_mutex_lock(think->l_chop);
		display_status(FORK, think);
		pthread_mutex_lock(think->r_chop);
		display_status(FORK, think);
	}
}

void	eat(t_philo *think)
{
	if (check_death(think) == 0)
	{
		take_chopsticks(think);
		pthread_mutex_lock(&think->lock);
		pthread_mutex_lock(&think->eat_lock);
		think->eating = 1;
		pthread_mutex_unlock(&think->eat_lock);
		display_status(EAT, think);
		think->death_end = get_time() + think->data->death_time;
		if (think->data->eat_time + (think->data->sleep_time >
			think->data->think->data->eat_time ? think->data->sleep_time :
				think->data->eat_time) < think->death_end)
			go_sleep(think->death_end - get_time());
		else
			go_sleep(think->data->eat_time);
		pthread_mutex_lock(&think->eat_lock);
		think->eating = 0;
		pthread_mutex_unlock(&think->eat_lock);
		think->eat_count += 1;
		pthread_mutex_unlock(&think->lock);
		unlock_chopsticks(think);
	}
}
//printf("think->data->eat_time == %lu || think->death_end - get_time() == %lu\n", think->data->eat_time, think->death_end - get_time());
