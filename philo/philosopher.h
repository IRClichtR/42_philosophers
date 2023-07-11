/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:57:38 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/11 17:32:41 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>

typedef struct	s_philo
{
	char		*name;
	pthread_t	philosopher;
	int			eat;
	int			think;
	int			die;
}				t_philo;

void	ft_print(char *str, int fd);
int		ft_strlen(char *str);

#endif
