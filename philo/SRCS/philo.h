#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stddef.h> 

typedef struct	s_philo
{
	pthread_t		thinker;
	int				think_id;
	int				death;
	pthread_mutex_t	death_lock;
}				t_philo;	

typedef struct	s_data
{
	t_philo			*philo;
	int				nb_philo;
}				t_data;

void    del_memalloc(t_data *data);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		init_data(t_data *data, int ac, char **av);
int		resume(t_data *data);
void    str_error(char *msg, t_data *data);
#endif
