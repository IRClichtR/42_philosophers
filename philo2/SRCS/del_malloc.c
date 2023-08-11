#include "philo.h"

void	del_malloc(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	
	while (i < data->think_nb)
	{
		pthread_mutex_destroy(&data->think[i].lock);
		pthread_mutex_destroy(&data->chopstick[i]);
		i++;
	}
	free(data->tid);
	free(data->think);
	free(data->chopstick);
}
