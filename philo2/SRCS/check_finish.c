/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:25:59 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/18 10:27:15 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish(t_philo *think)
{
	pthread_mutex_lock(&think->data->finish_lock);
	if (think->data->round_nb > 0
		&& think->data->finish >= think->data->round_nb)
	{
		pthread_mutex_unlock(&think->data->finish_lock);
		return (1);
	}
	pthread_mutex_unlock(&think->data->finish_lock);
	return (0);
}
