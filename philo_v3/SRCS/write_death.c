/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:46:40 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/18 12:38:43 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_death(t_philo *think)
{
	display_status(DIED, think);
	pthread_mutex_lock(&think->data->death_lock);
	think->data->waisted = 1;
	pthread_mutex_unlock(&think->data->death_lock);
}
