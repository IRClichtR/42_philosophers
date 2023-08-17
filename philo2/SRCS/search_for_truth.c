/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_truth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:49:09 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/16 11:49:11 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	search_for_truth(t_philo *think)
{
	display_status("SLEEP", think);
	go_sleep(think->data->sleep_time);
}
