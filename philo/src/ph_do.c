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

void	ph_eats(t_philo *ph)
{
	if (ph->d_dinner->flag_d == 1)
		return ;
	print_log(ph, 1);
	ph->last_eat = passed_time(ph->d_dinner->begin_time);
	my_sleep((int)ph->d_dinner->tt_eat);
	ph->count_eat++;
}

void	ph_sleeps(t_philo *ph)
{
	if (ph->d_dinner->flag_d == 1 || ph->d_dinner->all_eat == 1)
		return ;
	print_log(ph, 2);
	my_sleep((int)ph->d_dinner->tt_sleep);
}

void	ph_thinks(t_philo *ph)
{
	if (ph->d_dinner->flag_d == 1 || ph->d_dinner->all_eat == 1)
		return ;
	print_log(ph, 3);
}

void	join_th(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->d_dinner->num_ph)
	{
		if (pthread_join(ph[i].th, NULL))
			printf("not join join_th\n");
		i++;
	}
	return ;
}

void	ph_died(t_philo *ph)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < ph->d_dinner->num_ph)
		{
			if (ph[i].count_eat == ph[i].d_dinner->num_must_eat)
			{
				ph[i].d_dinner->all_eat = 1;
				return ;
			}
			if (ph[i].d_dinner->tt_die + 1 <= \
			passed_time(ph[i].d_dinner->begin_time) - ph[i].last_eat)
			{
				ph[i].d_dinner->flag_d = 1;
				print_log(&ph[i], 4);
				return ;
			}
			i++;
			my_sleep(1);
		}
	}
}
