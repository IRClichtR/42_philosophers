/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resume_experiment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:28:02 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/24 15:07:47 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*roll_dice()
{
	int	value = (rand() % 6) + 1;
	int	*result = malloc(sizeof(int));
	*result = value;
	printf("%d\n", value);
	return((void *)result);
}

void	resume_experiment(t_philo *cond)
{
	int		i;
	int		*res;
	i = 0;
	cond->start_experiment = get_time();
	while (i < cond->fork_nb)
	{
		if (pthread_create(&cond->thinker[i], NULL, roll_dice, NULL) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < cond->fork_nb)
	{
		if (pthread_join(cond->thinker[i], (void **)&res) != 0)
			return ;
		i++;
	}
	free(res);
}
/*

WARNING 
segfault happens when destroying mutex at end of this function

initialize and destroy mutex every time they're used
5: is the number of philos
800: is the time a philosopher must fast to die
200: is the time a philosopher takes to eat
200: is the time a philosopher takes to sleep
7: are the times all the philos must eat in order to terminate the program
*/
