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

//int 		malloc_data(t_philo *ph, t_data *d_dinner)
//{
//	ph = (t_philo *)malloc(d_dinner->num_ph * sizeof(t_philo));
//	if (!ph)
//		return (1);
//	ph->th = (pthread_t *)malloc(d_dinner->num_ph * (sizeof(pthread_t)));
//	if (!ph->th)
//		return (1);
//	ph->fork = (pthread_mutex_t *)malloc(d_dinner->num_ph * sizeof
//			(pthread_mutex_t));
//	if (!ph->fork)
//		return (1);
//	return (0);
//}

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