/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:38:54 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/18 11:09:14 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *think)
{
	pthread_mutex_lock(&think->data->death_lock);
	if (think->data->waisted == 1)
	{
		pthread_mutex_unlock(&think->data->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&think->data->death_lock);
	return (0);
}
