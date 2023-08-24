/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:48:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/24 09:46:02 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

enum e_typeprint
{
	THINK = 1,
	EAT = 2,
	SLEEP = 3,
	FORK = 4,
	DIED = 0
};

enum e_chopstick
{
	LEFT = 1,
	RIGHT = 2,
	TAKE = 3,
	LEAVE = 4
};

typedef struct s_philo
{
	struct s_data	*data;
	int				think_id;
	uint64_t		death_end;
	int				eat_count;
	int				status;
	pthread_mutex_t	lock;
	pthread_mutex_t	*l_chop;
	pthread_mutex_t	*r_chop;
	int				*l_status;
	int				*r_status;
}				t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	pthread_t		monitor;
	t_philo			*think;
	int				think_nb;
	int				round_nb;
	uint64_t		start_time;
	uint64_t		death_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	int				waisted;
	int				finish;
	int				**chop_status;
	pthread_mutex_t	*chopstick;
	pthread_mutex_t	write;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	finish_lock;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	release;
}				t_data;

int 		check_chop(t_philo *think, int chopstick);
int			check_death(t_philo *think);
int			check_eating(t_philo *think);
int			check_finish(t_philo *think);
int			check_num(char **arg_chain);
int			check_time(u_int64_t time, u_int64_t death_end);
int			chop_trylock(t_philo *think);
void		*death_watch(void *arg);
void		del_malloc(t_data *data);
void		display_status(int status, t_philo *think);
int			do_1th(t_data *data);
int			do_multiple_thinkers(t_data *data);
void		eat(t_philo *think);
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*get_ataraxia(void *arg);
uint64_t	get_time(void);
int			go_sleep(useconds_t time);
int			init_data(t_data *data, int ac, char **av);
void		mod_chop_status(t_philo *think, int chopstick, int action);
void		search_for_truth(t_philo *think);
int			str_error(char *str, t_data *data);
void		write_death(t_philo *think);
void		write_finish(t_philo *think);
#endif
