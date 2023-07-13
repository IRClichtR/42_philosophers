/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resume_experiment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:28:02 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/12 15:28:04 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	routine()
{
	static int	i = 0;
	if (i == 0)
	{
		printf(" ----- PHILOSOPHERS ENTER THE ROOM ----- \n");
		printf("[%d] no one shall enter if they are not geometrician!\n", i);
	}
	if (i == 1)
		printf("[%d] I love sodomy!\n", i);
	if (i > 1)
		printf("[%d] Me too!\n", i);
	i+=1;
}

void	resume_experiment(t_philo *cond)
{
	int		i;
	void	*ptr;

	i = 0;
	ptr = &routine;
	while (i < cond->fork_nb)
	{
		if (pthread_create(&cond->thinker[i], NULL, ptr, NULL) != 0)
			return ;
		if (pthread_join(cond->thinker[i], NULL) != 0)
			return ;
		i++;
	}
}
