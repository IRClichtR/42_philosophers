/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_1th.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:45:35 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/16 11:45:37 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_1th(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &get_ataraxia, &data->think[0]))
		return (str_error("Error: pthread_create() error\n", data));
	pthread_detach(data->tid[0]);
	while (data->waisted == 0)
		go_sleep(0);
	del_malloc(data);
	return (0);
}
