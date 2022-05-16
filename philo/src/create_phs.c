/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_phs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:12:52 by lchristi          #+#    #+#             */
/*   Updated: 2022/04/26 21:13:50 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philosoph(void *ph)
{
	t_philo	*ph_tmp;

	ph_tmp = ph;
	if (ph_tmp->num % 2 == 0)
//		my_sleep(ph_tmp->d_dinner.tt_eat); //
		my_sleep(50);
	while (*ph_tmp->died != 1 && ph_tmp->count_eat != ph_tmp->d_dinner
	.num_must_eat)
	{
		pthread_mutex_lock(ph_tmp->left_fork);
		print_log(ph_tmp, 11);
		pthread_mutex_lock(ph_tmp->right_fork);
		print_log(ph_tmp, 12);
		ph_eats(ph_tmp);
		//print_put(ph_tmp, 11);
		pthread_mutex_unlock(ph_tmp->left_fork);
		//print_put(ph_tmp, 12);
		pthread_mutex_unlock(ph_tmp->right_fork);
		ph_sleeps(ph_tmp);
		ph_thinks(ph_tmp);
	}
	return ;
}

static void	create_loop(t_data *d_dinner, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < d_dinner->num_ph)
	{
		pthread_mutex_init(&ph->fork[i], NULL);
		ph[i].d_dinner = *d_dinner;
		ph[i].num = i + 1;
		ph[i].right_fork = &ph->fork[i];
		ph[i].last_eat = 0;
		ph[i].count_eat = 0;
		ph[i].died = &ph->flag;
		if (i != d_dinner->num_ph - 1) //
			ph[i].left_fork = &ph->fork[i + 1];
		else
			ph[i].left_fork = &ph->fork[0];
		if (pthread_create(&ph->th[i], NULL, (void *)&philosoph, (void *)(&ph[i])) != 0)
		{
			printf("not pthread_create! \n");
			return ;
		}
		printf("ph %d th = %lu\n", ph[i].num, (pthread_t)ph[i].th);
		i++;
	}
	usleep(10); // was 100
	ph_died(ph);
//	pthread_create(&ph->th[i], NULL, (void *)&ph_died, (void *)ph);
	return ;
}

void create_phs(t_data *d_dinner)
{
	t_philo	*ph;
	int		i;

	i = 0;
	ph = (t_philo *)malloc(d_dinner->num_ph * sizeof(t_philo));
	ph->th = (pthread_t *)malloc((d_dinner->num_ph) * (sizeof(pthread_t)));
	ph->fork = (pthread_mutex_t *)malloc((d_dinner->num_ph) * sizeof(pthread_mutex_t));

	pthread_mutex_init(&ph->message, NULL);
	d_dinner->begin_time = get_time();
	//print(d_dinner);
	create_loop(d_dinner, ph);
	//i = 0;
	pthread_join(ph->th[i], NULL);
	i = 0;
	while (i < d_dinner->num_ph)
	{
		pthread_mutex_destroy(&ph->fork[i++]);
	}
	//printf("after ph = %lu\n", ph->th[i]);
	printf("after join\n");
	pthread_mutex_destroy(&ph->message);
	free(ph->th);
	free(ph->fork);
	free(ph);
}
