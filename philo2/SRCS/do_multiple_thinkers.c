/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_multiple_thinkers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:45:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/18 14:41:53 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_multiple_thinkers(t_data *data)
{
	int			i;

	data->start_time = get_time(data);
	i = -1;
	while (++i < data->think_nb)
	{
		if (pthread_create(&data->tid[i], NULL, &get_ataraxia, \
			&data->think[i]) != 0)
			return (str_error("Error: thinker thread creation error", data));
	}
	i = -1;
	while (++i < data->think_nb)
	{
		if (pthread_join(data->tid[i], NULL))
			return (str_error("Error: pthread_join() error\n", data));
	}
	return (0);
}
