#include "philo.h"

int	go_sleep(useconds_t time)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(time / 10);
	return (0);
}


