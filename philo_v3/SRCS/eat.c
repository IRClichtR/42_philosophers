/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:46:05 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/24 11:57:12 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *think)
{
	if (check_death(think) == 0)
	{
		pthread_mutex_lock(&think->lock);
		display_status(EAT, think);
		think->death_end = get_time() + think->data->death_time;
		if (check_time(get_time() + think->data->eat_time, think->death_end) == -1)
		{
			//think->death_end = get_time() + think->data->death_time;
			go_sleep(think->death_end - get_time());
		}
		else
		{
			//think->death_end = get_time() + think->data->death_time;
			go_sleep(think->data->eat_time);
		}
		think->eat_count += 1;
		mod_chop_status(think, LEFT, LEAVE);
		mod_chop_status(think, RIGHT, LEAVE);
		search_for_truth(think);
		pthread_mutex_unlock(&think->lock);
	}
}
