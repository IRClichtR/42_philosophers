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

void	*monitor()
{
	if (finish == nb_thinker)
		return (/*END OF EXPERIMENT*/);
}

void	*life_of_a_philosopher(/*argument*/)
{
	// set up time to die
	// set up time to sleep
	// if l_fork available && r_fork available
	//		then initiate eating process
	// else think
	time_to_die = get_time() + time_to_die_param;
	while (get_time() <= time_to_die && rounds > 0)
	{
		if (l_fork && r_fork)
			if (eat() == -1)
				return (/*DEATH*/);
		else
			if (think_sleep() == -1)
				return (/*DEATH*/);;
		round--;
	}
	if (round == 0)
		return (/*FINISHED*/);
	else
		return (/*DEATH*/);
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
