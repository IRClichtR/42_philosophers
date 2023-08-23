/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chop_trylock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:58:43 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/23 21:08:46 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	chop_trylock(t_philo *think)
{
	if (check_chop(think, RIGHT) == 0 && check_chop(think, LEFT) == 0)
	{
//		if (think->data->think_nb % 2 != 0)
//		{
			if (think->think_id % 2 == 0)
			{
				mod_chop_status(think, RIGHT);
				mod_chop_status(think, LEFT);
			}
			else
			{
				mod_chop_status(think, LEFT);
				mod_chop_status(think, RIGHT);
			}
/*		}
		else
		{
			if (think->think_id < think->data->think_nb)
			{
				mod_chop_status(think, RIGHT);
				mod_chop_status(think, LEFT);
			}
			else
			{
				mod_chop_status(think, LEFT);
				mod_chop_status(think, RIGHT);
			}
		}
*/
	}
	else
		return (0);
	return (1);
}
