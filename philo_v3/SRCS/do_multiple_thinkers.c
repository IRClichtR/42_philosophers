/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_multiple_thinkers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:45:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/23 20:59:10 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	do_multiple_thinkers(t_data *data)
{
	int			i;

	i = -1;
//	pthread_mutex_lock(&data->release);
	data->start_time = get_time();
	if (pthread_create(&data->monitor, NULL, &death_watch, \
		&data->think[0]) != 0)
		return (str_error("Error: Monitor thread creation error", data));
	while (++i < data->think_nb)
	{
		if (pthread_create(&data->tid[i], NULL, &get_ataraxia, \
			&data->think[i]) != 0)
			return (str_error("Error: thinker thread creation error", data));
	}
//	pthread_mutex_unlock(&data->release);
	i = -1;
	while (++i < data->think_nb)
	{
		if (pthread_join(data->tid[i], NULL))
			return (str_error("Error: pthread_join() error\n", data));
	}
	if (pthread_join(data->monitor, NULL))
		return (str_error("Error: pthread_join() error\n", data));
	return (0);
}
