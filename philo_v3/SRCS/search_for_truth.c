/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_truth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:49:09 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/23 19:19:20 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	search_for_truth(t_philo *think)
{
	if (check_death(think) == 1)
		return ;
	display_status(SLEEP, think);
	if (check_time(get_time() + think->data->sleep_time, think->death_end) == -1)
		go_sleep(think->death_end - get_time());
	else
		go_sleep(think->data->sleep_time);
}
