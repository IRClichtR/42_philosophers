/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_truth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:49:09 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/18 14:56:24 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	search_for_truth(t_philo *think)
{
	if (check_death(think) == 1)
		return ;
	display_status(SLEEP, think);
	go_sleep(think->data->sleep_time);
}
