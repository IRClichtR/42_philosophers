#include "philo.h"

void	del_memalloc(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo)
		free(data->philo);
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philo[i].death_lock);
		i++;
	}
}
