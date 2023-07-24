/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:37:55 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/24 16:47:05 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	display_usage()
{
	ft_print("----- PHILOSOPHERS -----\n", 2);
	ft_print("Type valid arguments\n", 2);
	ft_print("<ARG1> number_of_philosophers (at least one) ", 2);
	ft_print(" <ARG2> time_to_die ", 2);
	ft_print("<ARG3> time_to_eat ", 2);
	ft_print("<ARG4> time_to_sleep\n", 2);
	ft_print("<OPTIONAL>[number_of_times_each_philosopher_must_eat]\n", 2);
}

void	display_error()
{
	ft_print("----- ERROR -----\n", 2);
	ft_print("Your mission was to create life and you failed miserably\n", 2);
	ft_print("\n\n", 2);
	display_usage();
}

void	display_gameover()
{
	ft_print("\n\n\n\n", 1);
	ft_print("----- END OF EXPERIMENT -----\n", 1);
	ft_print("Why should I fear death? If I am, death is not.", 1);
	ft_print(" If death is, I am not. Why should I fear that which cannot", 1);
	ft_print(" exist when I do?\n", 1);
}

int main(int ac, char **av)
{
	t_philo *conditions;

	if (ac > 6 || ac < 4 || ft_atoi(av[1]) < 1)
	{
		display_error();
		return(0);
	}
	conditions = malloc(sizeof(t_philo));
	init_experiment(av);
	if (conditions == NULL)
	{
		display_error();
		return (0);
	}
	resume_experiment(conditions);
	display_gameover();
	free(conditions);
	return (0);
}
