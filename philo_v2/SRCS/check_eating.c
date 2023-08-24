/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:03:21 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/18 09:59:40 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eating(t_philo *think)
{
	pthread_mutex_lock(&think->eat_lock);
	if (think->eating == 1)
	{
		pthread_mutex_unlock(&think->eat_lock);
		return (1);
	}
	pthread_mutex_unlock(&think->eat_lock);
	return (0);
}
