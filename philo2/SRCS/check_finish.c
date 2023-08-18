/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:25:59 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/18 16:02:27 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	write_end_of_rounds(t_philo *think)
{
	pthread_mutex_lock(&think->data->death_lock);
	think->data->waisted = 1;
	printf("----END OF ROUNDS----\n");
	pthread_mutex_unlock(&think->data->death_lock);
}

int	check_finish(t_philo *think)
{
	pthread_mutex_lock(&think->data->finish_lock);
	if (think->data->round_nb > 0
		&& think->data->finish >= think->data->round_nb)
	{
		write_end_of_rounds(think);
		pthread_mutex_unlock(&think->data->finish_lock);
		return (1);
	}
	pthread_mutex_unlock(&think->data->finish_lock);
	return (0);
}
