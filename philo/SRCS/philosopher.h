/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:57:38 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/24 18:11:01 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct	s_thinker
{
	struct s_data	*data;
	pthread_t		life;
	int				philo_id;
	int				eating;
	uint64_t		time_to_die;
	int				eat_lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	lock;
}				t_thinker;

typedef struct	s_philo
{
	t_thinker		*thinker;
	int				fork_nb;
	u_int64_t		start_experiment;
	uint64_t		eat_time;
	uint64_t		think_time;
	uint64_t		die_time;
	uint64_t		sleep_time;
	int				round_nb;
	pthread_mutex_t	*forks;
}					t_philo;

int 		ft_atoi(char *nptr);
void		ft_print(char *str, int fd);
int			ft_strlen(char *str);
u_int64_t	get_time(void);
int			go_sleep(useconds_t time);
t_philo		*init_experiment(char **av);
void    	resume_experiment(t_philo *cond);

#endif
