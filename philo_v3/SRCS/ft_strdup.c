/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:28:57 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/21 12:43:26 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*copy;
	char	*str;

	i = 0;
	str = (char *)s;
	copy = malloc(sizeof (char) * ft_strlen(str) + 1);
	if (copy == NULL)
	{
		free(copy);
		return (NULL);
	}
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
