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
	if (ph->d_dinner.tt_die <= passed_time(ph->d_dinner.begin_time) -
	ph->last_eat)
	{
		ph->died = 1;
		print_log(ph, 4);
//		return ;
		exit(0);
	}
	//if (*ph->died == 1)
//	{
//		print_log(ph, 4);
//		//exit(0);
//		return ;
//	}
		//		return ;
	print_log(ph, 1);
	my_sleep((int)ph->d_dinner.tt_eat);
	ph->last_eat = passed_time(ph->d_dinner.begin_time); // ????
	ph->count_eat++;
}

void ph_sleeps(t_philo *ph)
{
	if (ph->died == 1)
		return ;
	print_log(ph, 2);
	my_sleep((int)ph->d_dinner.tt_sleep);
}


void ph_thinks(t_philo *ph)
{
	if (ph->died == 1)
		return ;
	print_log(ph, 3);
}

void ph_died(t_philo *ph)
{
	int i;

	while(1)
	{
		i = 0;
		while (i < ph->d_dinner.num_ph)
		{
			if (ph[i].d_dinner.tt_die < passed_time(ph[i].d_dinner.begin_time) - ph[i].last_eat)
			{
//				printf("%d ph begin = %d last eat = %d\n", ph[i].num, ph[i].d_dinner.begin_time, ph[i].last_eat);
				//ph[i].died = 1;
				ph[i].flag = 1;
				print_log(ph, 4);
				return ;
			}
			i++;
			my_sleep(ph[i].d_dinner.tt_die);
		}
	}
}
