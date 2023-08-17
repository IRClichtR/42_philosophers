/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:38:54 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/17 09:39:00 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *think)
{
	int	res;

	pthread_mutex_lock(&think->data->death_lock);
	if (think->data->waisted == 1)
		res = 1;
	else
		res = 0;
	pthread_mutex_unlock(&think->data->death_lock);
	return (res);
}
