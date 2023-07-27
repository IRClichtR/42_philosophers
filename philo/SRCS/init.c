#include "philo.h"

static void	init_death(t_data *data)
{
	data->death = 0;
	pthread_mutex_init(death_lock);
}

int	init_data(t_data *data, int ac, char **av)
{
	int	philo_nb;
	int	i;

	i = 0;
	philo_nb = ft_atoi(av[1]);
	data->thinkers = malloc(philo_nb * sizeof(pthread_t));
	think_id = malloc(philo_nb * sizeof(int));
	while (i < philo_nb)
	{
		think_id[i] = i + 1;
		i++;
	}
	init_death(data);
	return (0);
}
