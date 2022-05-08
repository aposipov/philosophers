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
	if (ph->flag == 1)
		return;
	if (print_log(ph, 1))
		return NULL;
	ph->last_eat = passed_time(ph->d_dinner.begin_time); // ????
	my_sleep((int)ph->d_dinner.tt_eat);
	ph->count_eat++;
}

void ph_sleeps(t_philo *ph)
{
	if (ph->flag == 1)
		return ;
	if (print_log(ph, 2))
		return NULL;
	my_sleep((int)ph->d_dinner.tt_sleep);
}


void ph_thinks(t_philo *ph)
{
	if (ph->flag == 1)
		return ;
	if (print_log(ph, 3))
		return NULL;
}

void ph_died(t_philo *ph)
{
	int i;

	while(1)
	{
		i = 0;
		while (i < ph->d_dinner.num_ph)
		{
			if (ph[i].d_dinner.tt_die + 1  <= passed_time(ph[i].d_dinner.begin_time) - ph[i].last_eat)
			{
				*ph[i].died = 1;
				print_log(ph, 4);
				return ;
			}
			i++;
			my_sleep((int)(ph[i].d_dinner.tt_die));
		}
	}
}
