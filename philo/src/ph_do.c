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
	{
		printf(DC"%d PH is DIED! eats\n"NC, ph->num);
		exit (0);
		//return (1);
	}
	printf(GREEN"%d ph %d is eating\n"NC, passed_time(ph->d_dinner.begin_time),
		   ph->num);
	ph->last_eat = passed_time(ph->d_dinner.begin_time);
	printf(RED"ph %d last eat = %d\n"NC, ph->num, ph->last_eat);
	//usleep(ph->d_dinner.tt_eat * mls);
	my_sleep((int)ph->d_dinner.tt_eat);
	//printf(RED"ph %d mysleep = %d\n", ph->num, (int)(my_sleep((int)ph->d_dinner.tt_eat)));
	ph->count_eat++;
}

void ph_sleeps(t_philo *ph)
{
	if (ph->d_dinner.died == 1)
	{
		printf(DC"%d PH is DIED! sleeps\n"NC, ph->num);
		exit (0);
		//return (1);
	}
	printf(BLUE"%d ph %d is sleeping\n"NC, passed_time(ph->d_dinner
	.begin_time), ph->num);
	my_sleep((int)ph->d_dinner.tt_sleep);
	//usleep(ph->d_dinner.tt_sleep * mls);
}


void ph_thinks(t_philo *ph)
{
	if (ph->d_dinner.died == 1)
	{
		printf(DC"%d PH is DIED! thinks\n"NC, ph->num);
		exit (0);
		//return (1);
	}
	printf(CYAN"%d ph %d is thinking\n"NC, passed_time(ph->d_dinner
	.begin_time), ph->num);
}

void ph_died(t_philo *ph)
{
	int i = 1;

	while(1)
	{
		while (i < ph->d_dinner.num_ph)
		{
			if (ph[i].d_dinner.tt_die + 1 <= passed_time((ph[i].d_dinner.begin_time -ph[i].last_eat )))
			{
//				printf("ph %d tt_die = %d, passed = %d\n", ph->num, ph[i].d_dinner.tt_die,
//					   passed_time((int)(ph[i].d_dinner.begin_time-ph[i].last_eat)));
				ph[i].d_dinner.died = 1;
//				pthread_mutex_lock(&ph->d_dinner.message);
//				printf("STOP\n");
//				pthread_mutex_unlock(&ph->d_dinner.message);
//				return (1);
			}
			i++;
			my_sleep(1);
		}
		i = 1;
	}

}