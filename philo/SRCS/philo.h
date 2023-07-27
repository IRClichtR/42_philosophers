#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_data
{
	pthread_t		*thinkers;
	int				*think_id;
	int				death;
	pthread_mutex_t	death_lock;
}				t_data;

int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		init_data(t_data *data, int ac, char **av);
int		resume(t_data *data);
#endif

