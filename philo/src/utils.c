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