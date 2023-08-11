#include "philo.h"

static void	unlock_chopsticks(t_philo *think)
{
	pthread_mutex_unlock(think->l_chop);
	pthread_mutex_unlock(think->r_chop);
	search_for_truth(think);
}

static void unlock_1_chop(t_philo *think, int lock_left, int lock_right)
{
	if (lock_left == 0)
	{
		display_status("FORK", think);
		pthread_mutex_unlock(think->l_chop);
	}
	else if (lock_right == 0)
	{
		display_status("FORK", think);
		pthread_mutex_unlock(think->r_chop);
	}
}

static int	take_chopsticks(t_philo *think)
{
	int	lock_left;
	int	lock_right;

	if (think->data->think_nb == 1)
	{
		pthread_mutex_lock(think->r_chop);
		display_status("FORK", think);
		return (-1);
	}
	lock_right = pthread_mutex_lock(think->r_chop);
	lock_left = pthread_mutex_lock(think->l_chop);
	if (lock_right == 0 && lock_left == 0)
	{
		display_status("FORK", think);
		display_status("FORK", think);
		return (0);
	}
	unlock_1_chop(think, lock_left, lock_right);
	return (-1);
}

void	eat(t_philo *think)
{
	if (take_chopsticks(think) == 0 
	&& think->eat_count < think->data->round_nb)
	{
		pthread_mutex_lock(&think->lock);
		think->eating = 1;
		think->death_end = get_time() + think->data->death_time;
		display_status("EAT", think);
		think->eat_count++;
		go_sleep(think->data->eat_time);
		think->eating = 0;
		think->eat_count += 1;
		pthread_mutex_unlock(&think->lock);
		unlock_chopsticks(think);
	}
}
