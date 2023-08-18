/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:46:05 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/18 16:33:00 by ftuernal         ###   ########.fr       */
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

static void	take_one_chopstick(t_philo *think)
{
	pthread_mutex_lock(think->r_chop);
	display_status(FORK, think);
	pthread_mutex_unlock(think->r_chop);
	go_sleep(think->death_end);
}

void	eat(t_philo *think)
{
	if (check_death(think) == 0)
	{
		if (think->data->think_nb == 1)
			take_one_chopstick(think);
		else
		{
			take_chopsticks(think);
			pthread_mutex_lock(&think->lock);
			pthread_mutex_lock(&think->eat_lock);
			think->eating = 1;
			pthread_mutex_unlock(&think->eat_lock);
			display_status(EAT, think);
			think->death_end = get_time(think->data) + think->data->death_time;
			go_sleep(think->data->eat_time);
			pthread_mutex_lock(&think->eat_lock);
			think->eating = 0;
			pthread_mutex_unlock(&think->eat_lock);
			think->eat_count += 1;
			pthread_mutex_unlock(&think->lock);
			unlock_chopsticks(think);
		}
	}
printf("Am i here ?");
}
