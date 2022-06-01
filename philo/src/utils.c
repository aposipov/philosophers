/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:16:03 by lchristi          #+#    #+#             */
/*   Updated: 2022/04/26 21:16:12 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	old;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' \
					|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		old = num;
		num = num * 10 + (nptr[i++] - '0');
		if ((old < 0 && num > 0) || (old > 0 && num < 0))
			return ((sign == 1) * -1);
	}
	return ((int)(num * sign));
}

long int	get_time(void)
{
	struct timeval	t_start;

	gettimeofday(&t_start, NULL);
	return (t_start.tv_sec * 1000 + t_start.tv_usec / 1000);
}

void	my_sleep(int ms)
{
	long	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(1);
}

int	passed_time(long int begin_time)
{
	return ((int)(get_time() - begin_time));
}
