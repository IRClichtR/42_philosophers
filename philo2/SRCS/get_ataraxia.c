#include "philo.h"

static void	*socrates_watch(void *arg)
{
	t_philo	*think;

	think = (t_philo *)arg;
	while (think->data->waisted == 0)
	{
		pthread_mutex_lock(&think->lock);
		if (get_time() >= think->death_end && think->eating == 0 
			&& think->data->waisted == 0)
		{
			display_status("DEAD", think);
			think->data->waisted = 1;
		}
		if (think->eat_count == think->data->round_nb)
		{
			pthread_mutex_lock(&think->data->lock);
			think->data->finish++;
			pthread_mutex_unlock(&think->data->lock);
		}
		pthread_mutex_unlock(&think->lock);
	}
	return ((void *)0);
}

void	*get_ataraxia(void *arg)
{
	t_philo	*think;

	think = (t_philo *)arg;
	think->death_end = think->data->death_time + get_time();
	if (pthread_create(&think->t1, NULL, &socrates_watch, (void *)think) != 0)
		return ((void *)1);
	while (think->data->waisted == 0)
	{
		eat(think);
		display_status("THINK", think);
	}
	if (pthread_join(think->t1, NULL) != 0)
		return ((void *)1);
	return ((void *)0);
}
