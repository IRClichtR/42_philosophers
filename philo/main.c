/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:37:55 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/11 17:45:48 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	display_usage()
{
	ft_print("----- PHILOSOPHERS -----\n", 1);
	ft_print("Type valid arguments\n", 1);
	ft_print("<ARG1> number_of_philosophers ", 1);
	ft_print("<ARG2> time_to_die ", 1);
	ft_print("<ARG3>time_to_eat ", 1);
	ft_print("<ARG4>time_to_sleep\n", 1);
	ft_print("<OPTIONAL>[number_of_times_each_philosopher_must_eat]\n", 1);
}

void	display_error()
{
	ft_print("----- ERROR -----\n");
	ft_print("Your mission was to create life and you failed miserably\n");
	ft_print("\n\n");
	display_usage();
}

void	

int main(int ac, char **av)
{
	int	forks;

	if (ac > 5 || ac < 4)
	{
		display_usage();
		return(0);
	}
	forks = ft_atoi(av[1]);
	if (fork < 1)
	{
		display_error();
		return (1);
	}
	return (0);
}
