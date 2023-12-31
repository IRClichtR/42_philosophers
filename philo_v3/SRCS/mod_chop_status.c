/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_chop_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:22:41 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/24 09:44:29 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mod_chop_status(t_philo *think, int chopstick, int action)
{
	if (chopstick == LEFT)
	{
		pthread_mutex_lock(think->l_chop);
		if (action == TAKE)
		{
			display_status(FORK, think);
			*think->l_status = 1;
		}
		else
			*think->l_status = 0;
		pthread_mutex_unlock(think->l_chop);
	}
	else
	{
		pthread_mutex_lock(think->r_chop);
		if (action == TAKE)
		{
			display_status(FORK, think);
			*think->r_status = 1;
		}
		else
			*think->r_status = 0;
		pthread_mutex_unlock(think->r_chop);
	}
}
