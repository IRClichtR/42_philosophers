#include "philo.h"

void	*roll_dice(void *arg)
{
	t_philo	*thinker;
	int		rand_nb;

	thinker = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&thinker->death_lock);
		rand_nb = rand() %	 50 + 1;
		printf("[%d] %d\n", thinker->think_id, rand_nb);
		if (rand_nb == 5)
		{
			printf("trigger has been pulled\n");
			break ;
		}
		else
		{
			printf("[%d] %d bad luck :-(\n", thinker->think_id, rand_nb);
			break ;
		}
	}
	return ((void *)0);
}

int	resume(t_data *data)
{
	int	i;

	i = 0;
	printf("-----RESUME GAME-----\n");
	while (i < data->nb_philo)
	{
printf("THINKER_ID == %d\n", data->philo[i].think_id);
		if (pthread_create(&data->philo[i].thinker, NULL, roll_dice, (void *)&data->philo[i]) != 0)
			return (str_error("pthread_create failure\n", data), -1);
		pthread_mutex_unlock(&data->philo[i].death_lock);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].thinker, NULL) != 0)
			return (str_error("pthread_create failure\n", data), -1);
		i++;
	}
	printf("-----END OF GAME-----\n");
	return (0);
}
