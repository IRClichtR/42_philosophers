/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:46:05 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/17 12:01:04 by ftuernal         ###   ########.fr       */
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
	if (check_death(think) == 0)
	{
		if (think->think_id % 2 != 0)
		{
			pthread_mutex_lock(think->r_chop);
			display_status("FORK", think);
			pthread_mutex_lock(think->l_chop);
			display_status("FORK", think);
		}
		else
		{
			pthread_mutex_lock(think->l_chop);
			display_status("FORK", think);
			pthread_mutex_lock(think->r_chop);
			display_status("FORK", think);
		}
	}
}

void	eat(t_philo *think)
{
	if (check_death(think) == 0)
	{
		take_chopsticks(think);
		pthread_mutex_lock(&think->lock);
		if (check_death(think) == 0)
		{
			think->eating = 1;
			display_status("EAT", think);
		}
		think->death_end = get_time() + think->data->death_time;
		go_sleep(think->data->eat_time);
		think->eating = 0;
		think->eat_count += 1;
		pthread_mutex_unlock(&think->lock);
		unlock_chopsticks(think);
	}
	else
		return ;
}
