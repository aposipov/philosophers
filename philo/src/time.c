/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:15:36 by lchristi          #+#    #+#             */
/*   Updated: 2022/04/26 21:15:49 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int get_time(void)
{
	struct timeval t_start;

	gettimeofday(&t_start, NULL);
	return (t_start.tv_sec * 1000 + t_start.tv_usec / 1000);
}

void	my_sleep(int ms)  // rewrite??
{
	long	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(50);
}

int	passed_time(long int begin_time)
{
	return ((int)(get_time() - begin_time));
}
