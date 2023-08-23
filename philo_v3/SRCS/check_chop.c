/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:15:36 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/23 17:37:37 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_chop(t_philo *think, int chopstick)
{
	int	status;

	if (chopstick == LEFT)
	{
		pthread_mutex_lock(think->l_chop);
		if (*think->l_status == 1)
			status = 1;
		else
			status = 0;
		pthread_mutex_unlock(think->l_chop);
	}
	else
	{
		pthread_mutex_lock(think->r_chop);
		if (*think->r_status == 1)
			status = 1;
		else
			status = 0;
		pthread_mutex_unlock(think->r_chop);
	}
	return (status);
}
