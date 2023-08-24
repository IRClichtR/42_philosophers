/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:47:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/24 13:07:19 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	struct_alloc(t_data *data)
{
	data->tid = malloc(data->think_nb * sizeof(pthread_t));
	if (!data->tid)
		return (str_error("Error: pthread_t alloc failed\n", data));
	data->chopstick = malloc(data->think_nb * sizeof(pthread_mutex_t));
	if (!data->chopstick)
		return (str_error("Error: chopstick alloc failed\n", data));
	data->think = malloc(data->think_nb * sizeof(t_philo));
	if (!data->think)
		return (str_error("Error t_philo struct alloc failed\n", data));
	return (0);
}

static void	fork_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->think_nb)
	{
		pthread_mutex_init(&data->chopstick[i], NULL);
		i++;
	}
	data->think[0].l_chop = &data->chopstick[0];
	if (data->think_nb > 1)
	{
		data->think[0].r_chop = &data->chopstick[data->think_nb - 1];
		i = 0;
		while (++i < data->think_nb)
		{
			data->think[i].l_chop = &data->chopstick[i];
			data->think[i].r_chop = &data->chopstick[i - 1];
		}
	}
}

static void	init_think(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->think_nb)
	{
		data->think[i].data = data;
		data->think[i].think_id = i + 1;
		data->think[i].death_end = data->death_time;
		data->think[i].eat_count = 0;
		data->think[i].status = 0;
		pthread_mutex_init(&data->think[i].lock, NULL);
		i++;
	}
}

static int	init_conditions(t_data *data, char **av, int ac)
{
	data->think_nb = ft_atoi(av[1]);
	data->death_time = (uint64_t)ft_atoi(av[2]);
	data->eat_time = (uint64_t)ft_atoi(av[3]);
	data->sleep_time = (uint64_t)ft_atoi(av[4]);
	if (ac == 6)
		data->round_nb = ft_atoi(av[5]);
	else
		data->round_nb = -1;
	if (data->think_nb < 1 || data->death_time < 0 || data->eat_time < 0
		|| data->sleep_time < 0)
		return (str_error("Error: Bad arguments!\n", data), -1);
	data->waisted = 0;
	data->finish = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->death_lock, NULL);
	pthread_mutex_init(&data->finish_lock, NULL);
	pthread_mutex_init(&data->time_lock, NULL);
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	if (init_conditions(data, av, ac) != 0)
		return (-1);
	if (struct_alloc(data) != 0)
		return (-1);
	fork_init(data);
	init_think(data);
	return (0);
}
