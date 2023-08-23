/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:54:43 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/23 21:32:32 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_finish(t_philo *think)
{
	pthread_mutex_lock(&think->data->finish_lock);
	think->data->finish++;
	think->status = -1;
	pthread_mutex_unlock(&think->data->finish_lock);
}
