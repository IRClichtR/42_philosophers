/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:45:14 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/23 17:35:36 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	del_malloc(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->finish_lock);
	while (++i < data->think_nb)
		free(data->chop_status[i]);
	i = -1;
	while (++i < data->think_nb)
	{
		pthread_mutex_destroy(&data->think[i].lock);
		pthread_mutex_destroy(&data->chopstick[i]);
	}
	free(data->chop_status);
	free(data->tid);
	free(data->think);
	free(data->chopstick);
}
