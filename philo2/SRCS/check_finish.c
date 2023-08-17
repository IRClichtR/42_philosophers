/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:25:59 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/17 10:26:01 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish(t_philo *think)
{
	int	res;
	pthread_mutex_lock(&think->data->finish_lock);
	if (think->data->finish >= think->data->round_nb)
		res = 1;
	else
		res = 0;
	pthread_mutex_unlock(&think->data->finish_lock);
	return (res);
}
