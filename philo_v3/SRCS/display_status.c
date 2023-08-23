/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:44:50 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/23 19:47:15 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mutex(t_philo *think, char *str, int type_print)
{
	uint64_t	time;
	static int	stop = 0;

	if (check_death(think) == 1)
		return ;
	pthread_mutex_lock(&think->data->write);
	if (stop == 1)
	{
		pthread_mutex_unlock(&think->data->write);
		return ;
	}
	time = get_time() - think->data->start_time;
	printf(str, time, think->think_id);
	if (type_print == DIED)
		stop = 1;
	pthread_mutex_unlock(&think->data->write);
}

void	display_status(int type_print, t_philo *think)
{
	if (check_death(think) == 1)
		return ;
	if (type_print == FORK)
		print_mutex(think, "%lu %d has taken a fork\n", type_print);
	else if (type_print == EAT)
		print_mutex(think, "%lu %d is eating\n", type_print);
	else if (type_print == SLEEP)
		print_mutex(think, "%lu %d is sleeping\n", type_print);
	else if (type_print == THINK)
		print_mutex(think, "%lu %d is thinking\n", type_print);
	else if (type_print == DIED)
		print_mutex(think, "%lu %d died\n", type_print);
}
