/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:14:54 by lchristi          #+#    #+#             */
/*   Updated: 2022/04/26 21:15:07 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void ph_eats(t_philo *ph)
{
	if (ph->d_dinner.died == 1)
		printf("DIE! function\n");
	printf(GREEN"%d ph %d is eating\n"NC, passed_time(ph->d_dinner.begin_time),
		   ph->num);
	ph->last_eat = passed_time(ph->d_dinner.begin_time);
	my_sleep((int)ph->d_dinner.tt_eat);
	ph->count_eat++;
}

void ph_sleeps(t_philo *ph)
{
	if (ph->d_dinner.died == 1)
		printf("DIE! function\n");
	printf(BLUE"%d ph %d is sleeping\n"NC, passed_time(ph->d_dinner
	.begin_time), ph->num);
	my_sleep((int)ph->d_dinner.tt_sleep);
}


void ph_thinks(t_philo *ph)
{
	if (ph->d_dinner.died == 1)
		printf("DIE! function\n");
	printf(CYAN"%d ph %d is thinking\n"NC, passed_time(ph->d_dinner
	.begin_time), ph->num);
}

void ph_die(t_philo *ph)
{
	int i = 0;

	if (ph->d_dinner.tt_die + 1 <= passed_time(ph->d_dinner.begin_time-ph[i].last_eat))
		printf("DIE\n");

}