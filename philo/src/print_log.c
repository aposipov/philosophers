/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:15:48 by lchristi          #+#    #+#             */
/*   Updated: 2022/06/01 22:15:50 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_log(t_philo *ph_tmp, int n)
{
	pthread_mutex_lock(&ph_tmp->message);
	if (n == 4)
	{
		printf(RED"%d %d died\n"NC, \
		passed_time(ph_tmp->d_dinner->begin_time), ph_tmp->num);
		pthread_mutex_unlock(&ph_tmp->message);
		return ;
	}
	else if (n == 11 && ph_tmp->d_dinner->flag_d != 1)
		printf("%d %d has taken a left fork\n", \
		passed_time(ph_tmp->d_dinner->begin_time), ph_tmp->num);
	else if (n == 12 && ph_tmp->d_dinner->flag_d != 1)
		printf("%d %d has taken a right fork\n", \
		passed_time(ph_tmp->d_dinner->begin_time), ph_tmp->num);
	else if (n == 1)
		printf(GREEN"%d %d is eating\n"NC, \
		passed_time(ph_tmp->d_dinner->begin_time), ph_tmp->num);
	else if (n == 2)
		printf(BLUE"%d %d is sleeping\n"NC, \
		passed_time(ph_tmp->d_dinner->begin_time), ph_tmp->num);
	else if (n == 3)
		printf(CYAN"%d %d is thinking\n"NC, \
		passed_time(ph_tmp->d_dinner->begin_time), ph_tmp->num);
	pthread_mutex_unlock(&ph_tmp->message);
	return ;
}
