/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:44:50 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/17 13:06:57 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_status(char *status, t_philo *think)
{
	uint64_t	time;

	time = get_time() - think->data->start_time;
	pthread_mutex_lock(&think->data->write);
	if (ft_strncmp("FORK", status, 4) == 0 && check_death(think) == 0)
		printf("%lu %d has taken a fork\n", time, think->think_id);
	else if (ft_strncmp("EAT", status, 3) == 0 && check_death(think) == 0)
		printf("%lu %d is eating\n", time, think->think_id);
	else if (ft_strncmp("SLEEP", status, 5) == 0 && check_death(think) == 0)
		printf("%lu %d is sleeping\n", time, think->think_id);
	else if (ft_strncmp("THINK", status, 5) == 0 && check_death(think) == 0)
		printf("%lu %d is thinking\n", time, think->think_id);
	else if (ft_strncmp("DEAD", status, 4) == 0)
		printf("%lu %d died\n", time, think->think_id);
//	else
//		printf("[%d] I continue [%s] even if I should not\n", think->think_id, status);
	pthread_mutex_unlock(&think->data->write);
}
