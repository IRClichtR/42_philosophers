/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_1th.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:45:35 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/21 12:24:21 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*th_ataraxia(void *arg)
{
	t_philo	*think;

	think = (t_philo *)arg;
	display_status(FORK, think);
	go_sleep(think->data->death_time);
	display_status(DIED, think);
	return ((void *)0);
}

int	do_1th(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &th_ataraxia, &data->think[0]))
		return (str_error("Error: pthread_create() error\n", data));
	if (pthread_join(data->tid[0], NULL))
		return (str_error("Error: pthread_join() error\n", data));
	del_malloc(data);
	return (0);
}
