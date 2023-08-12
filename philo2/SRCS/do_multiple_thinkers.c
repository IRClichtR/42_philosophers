#include "philo.h"

void	*monitor(void *arg)
{
	t_philo	*think;

	think = (t_philo *)arg;
	while (think->data->waisted == 0)
	{
		pthread_mutex_lock(&think->data->lock);
		if (think->data->finish >= think->data->round_nb 
			|| think->data->waisted == 1)
			think->data->waisted = 1;
		pthread_mutex_unlock(&think->data->lock);
	}
	return ((void *)0);
}

int	do_multiple_thinkers(t_data *data)
{
	pthread_t	aletheia;
	int			i;

	data->start_time = get_time();
	i = 0;
	if (data->round_nb > 0)
	{
		if (pthread_create(&aletheia, NULL, &monitor, &data->think[0]) != 0)
			return (str_error("Error: monitor thread error\n", data));
		go_sleep(1);
	}
	while (i < data->think_nb)
	{
		if (pthread_create(&data->tid[i], NULL, &get_ataraxia,\
			&data->think[i]) != 0)
			return (str_error("Error: thinker thread creation error", data));
		i++;
	}
	i = 0;
	while (i < data->think_nb)
	{
		if (pthread_join(data->tid[i], NULL))
			return (str_error("Error: pthread_join() error\n", data));
		i++;
	}
	return (0);
}
