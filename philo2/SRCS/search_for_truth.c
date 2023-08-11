#include "philo.h"

void	search_for_truth(t_philo *think)
{
	display_status("SLEEP", think);
	go_sleep(think->data->sleep_time);
}
