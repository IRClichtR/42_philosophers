/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:57:38 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/12 14:58:09 by ftuernal         ###   ########.fr       */
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

typedef struct	s_philo
{
	pthread_t	*thinker;
	int			fork_nb;
	int			eat_time;
	int			think_time;
	int			die_time;
}				t_philo;

int 	ft_atoi(char *nptr);
void	ft_print(char *str, int fd);
int		ft_strlen(char *str);

#endif