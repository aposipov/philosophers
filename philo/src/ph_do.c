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
	if (ph->d_dinner->flag_d == 1)
	{
		return ;
	}
	print_log(ph, 1);
	ph->last_eat = passed_time(ph->d_dinner->begin_time);
	my_sleep((int)ph->d_dinner->tt_eat);
	ph->count_eat++;
}

void ph_sleeps(t_philo *ph)
{
	if (ph->d_dinner->flag_d == 1)
	{
		return ;
	}
	print_log(ph, 2);
	my_sleep((int)ph->d_dinner->tt_sleep);
}


void ph_thinks(t_philo *ph)
{
	if (ph->d_dinner->flag_d == 1)
	{
		return ;
	}
	print_log(ph, 3);
}

void join_th(t_philo *ph)
{
	int i = 0;
//	if (pthread_mutex_unlock(&ph->message))
//		printf("unlock in join\n");
//	while(i < ph->d_dinner->num_ph)
//	{
//		if (pthread_mutex_unlock(&ph->fork[i]))
//			printf("unlock fork in join\n");
//		i++;
//	}
//	i = 0;
	while(i < ph->d_dinner->num_ph)
	{
		//printf("in join %lu\n", ph[i].th);
		if (pthread_join(ph[i].th, NULL))
			printf("not func join\n");
		i++;
	}
	return ;
}

void ph_died(t_philo *ph)
{
	int i;
	//int time;

	while(1)
	{
		i = 0;
		while (i < ph->d_dinner->num_ph)
		{
			if (ph[i].count_eat == ph[i].d_dinner->num_must_eat)
			{
				//pthread_join(*ph[i].th, NULL);
				//ph[i].eat_all = 1;
				join_th(ph);
				return ;
			}
			if (ph[i].d_dinner->tt_die + 1 <= passed_time(ph[i]
			.d_dinner->begin_time) - ph[i].last_eat)
			{
				ph[i].d_dinner->flag_d = 1;
				print_log(&ph[i], 4);
//				time = passed_time(ph[i].d_dinner->begin_time) -
//									  ph[i].last_eat;
//				pthread_mutex_lock(&ph[i].message);
//				printf(RED"%d %d ph passed time = %d\n"NC, passed_time
//						(ph[i].d_dinner->begin_time), ph[i].num, time);
//				printf(RED"%d PH is DIED! FLAG = %d\n"NC, ph[i].num,
//					   ph[i].d_dinner->flag_d);
//				pthread_mutex_unlock(&ph[i].message);
				join_th(ph);
				return ;
			}
			i++;
			my_sleep(10);
		}
	}
}
