#include "philo.h"

static int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(data->nb_philo * sizeof(t_philo));
	if (!data->philo)
		return (str_error("t_philo struc alloc failed\n", data), -1);
	while (i < data->nb_philo)
	{
		data->philo->think_id = i + 1;
printf("IN INIT_DATA THINK_ID == %d\n", data->philo->think_id);
		data->philo->death = 0;
		pthread_mutex_init(&data->philo[i].death_lock, NULL);
		i++;
	}
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	(void)ac;
	data->nb_philo = ft_atoi(av[1]);
	if (data->nb_philo < 1)
		return (str_error("Error: nb philo < 1\n", data), -1);
	if (init_philo(data) != 0)
		return (str_error("Error: t_philo struct init\n", data), -1);
	return (0);
}
