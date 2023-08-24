/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:47:34 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/18 14:54:20 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	go_sleep(useconds_t time)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(time / 10);
	return (0);
}
