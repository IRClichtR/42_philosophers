#include "philosopher.h"

void	display_message(char *str, /*STRUCTURE*/)
{
	uint64_t	time;

	pthread_mutex_lock(/*write mutex*/)
	time = get_time() - /*start_time*/;
	pthread_mutex_unlock(/*write mutex*/);
	if (ft_strncmp(str, "DEATH", 5) && death_value == 0)
	{
		printf("time string of death\n");
		death_value == 1;
	}
	else
		printf("%llu %s\n", time, str);
}
