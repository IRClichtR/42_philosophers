/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:19:26 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/24 12:19:28 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eat()
{
	
	if (get_time() <= time_to_die && (l_fork && r_fork))
	{
		take_fork(l_fork);
		take_fork(r_fork);
	}
	else
		return (/*DEATH SIGNAL*/);
	time_to_die = -1;
	go_sleep(time_to_eat);
	time_to_die = get_time() + time_to_die;
	return (/*SUCCESS SIGNAL*/);
}
