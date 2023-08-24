/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:45:14 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/24 13:26:51 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	del_malloc(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->finish_lock);
	while (i < data->think_nb)
	{
		pthread_mutex_destroy(&data->think[i].lock);
		pthread_mutex_destroy(&data->chopstick[i]);
		i++;
	}
	free(data->tid);
	free(data->think);
	free(data->chopstick);
}
