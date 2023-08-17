/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_multiple_thinkers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:45:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/17 13:24:34 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_philo	*think;

	think = (t_philo *)arg;
	while (check_death(think) == 0)
	{
		pthread_mutex_lock(&think->data->lock);
		if (check_finish(think) == 1)
		{
			pthread_mutex_lock(&think->data->death_lock);
			think->data->waisted = 1;
			pthread_mutex_unlock(&think->data->death_lock);
		}
		pthread_mutex_unlock(&think->data->lock);
	}
	return ((void *)0);
}

int	do_multiple_thinkers(t_data *data)
{
	pthread_t	aletheia;
	int			i;

	data->start_time = get_time();
	i = -1;
	if (data->round_nb > 0)
	{
		if (pthread_create(&aletheia, NULL, &monitor, &data->think[0]) != 0)
			return (str_error("Error: monitor thread error\n", data));
	}
	while (++i < data->think_nb)
	{
		if (pthread_create(&data->tid[i], NULL, &get_ataraxia, \
			&data->think[i]) != 0)
			return (str_error("Error: thinker thread creation error", data));
//		go_sleep(1);
	}
	i = -1;
	while (++i < data->think_nb)
	{
		if (pthread_join(data->tid[i], NULL))
			return (str_error("Error: pthread_join() error\n", data));
	}
	if (data->round_nb > 0)
		pthread_join(aletheia, NULL);
	return (0);
}
