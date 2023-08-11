#include "philo.h"

void	display_status(char *status, t_philo *think)
{
	uint64_t	time;

	time = get_time() - think->data->start_time;
	pthread_mutex_lock(&think->data->write);
	if (ft_strncmp("FORK", status, 4) == 0)
		printf("%llu [%d] has taken a fork\n", time, think->think_id);
	else if (ft_strncmp("EAT", status, 3) == 0)
		printf("%llu [%d] is eating\n", time, think->think_id);
	else if (ft_strncmp("SLEEP", status, 5) == 0)
		printf("%llu [%d] is sleeping\n", time, think->think_id);
	else if (ft_strncmp("THINK", status, 5) == 0)
		printf("%llu [%d] is thinking\n", time, think->think_id);
	else if (ft_strncmp("DEAD", status, 4) == 0)
		printf("%llu [%d] died\n", time, think->think_id);
	else
		printf("invalid config, please check string '%s'\n", status);
	pthread_mutex_unlock(&think->data->write);
}
