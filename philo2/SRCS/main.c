/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:48:21 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/16 11:48:23 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	display_usage(void)
{
	printf("Enter valid arguments:\n");
	printf("ARG1= number of philosophers\n");
	printf("ARG2= time to die\n");
	printf("ARG3= time to eat\n");
	printf("ARG4= time to sleep\n");
	printf("[optional] ARG5= number of meals\n");
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6 || check_av(av) != 0)
	{
		printf("Error: arguments error\n");
		display_usage();
		return (1);
	}
	if (init_data(&data, ac, av) != 0)
		return (1);
	if (data.think_nb == 1)
		return (do_1th(&data));
	if (do_multiple_thinkers(&data) != 0)
		return (str_error("Error: thread executing error\n", &data));
	printf("-----GAME OVER-----\n");
	del_malloc(&data);
	return (0);
}
