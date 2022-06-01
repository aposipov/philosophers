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

void	routine(void *ph)
{
	t_philo	*ph_tmp;

	ph_tmp = ph;
	if (ph_tmp->num % 2 == 0)
		my_sleep(ph_tmp->d_dinner->tt_eat / 2); //
	while (ph_tmp->d_dinner->flag_d != 1 && ph_tmp->count_eat !=
											ph_tmp->d_dinner->num_must_eat)
	{
		pthread_mutex_lock(ph_tmp->left_fork);
		print_log(ph_tmp, 11);
		if (ph_tmp->d_dinner->num_ph == 1)
		{
			pthread_mutex_unlock(ph_tmp->left_fork);
			return;
		}
		pthread_mutex_lock(ph_tmp->right_fork);
		print_log(ph_tmp, 12);
		ph_eats(ph_tmp);
		pthread_mutex_unlock(ph_tmp->left_fork);
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
		ph[i].d_dinner = d_dinner;
		ph[i].num = i + 1;
		ph[i].right_fork = &ph->fork[i];
		ph[i].last_eat = 0;
		ph[i].count_eat = 0;
		printf("%d adres %p\n", i, &ph[i].d_dinner->flag_d);
		if (i != d_dinner->num_ph - 1) //
			ph[i].left_fork = &ph->fork[i + 1];
		else
			ph[i].left_fork = &ph->fork[0];
		if (pthread_create(&ph[i].th, NULL, (void *)&routine, (void *)
		(&ph[i])))
		{
			printf("not pthread_create! \n");
			return ;
		}
		printf("%lu create\n", ph[i].th);
		//pthread_detach(ph[i].th);
		i++;
	}
	usleep(10);
	//pthread_detach(ph[i].th);
	//pthread_create(&monitor, NULL, (void *)&ph_died, (void *)ph);
	//pthread_join(monitor, NULL);
	ph_died(ph);
//	i =0;
//	while(i < ph->d_dinner->num_ph)
//	{
//		printf("in join %lu\n", ph[i].th);
//		if (pthread_join(ph[i].th, NULL))
//			printf("not func join\n");
//		i++;
//	}

	printf("%lu exit loop\n", ph->th);
	return ;
}

void create_phs(t_data *d_dinner)
{
	t_philo	*ph;
	int		i;
	pthread_t self;

	i = 0;
	ph = (t_philo *)malloc(d_dinner->num_ph * sizeof(t_philo));
	ph->fork = (pthread_mutex_t *)malloc((d_dinner->num_ph) * sizeof(pthread_mutex_t));

	if (pthread_mutex_init(&ph->message, NULL))
		printf("not init message\n");
	d_dinner->begin_time = get_time();
	create_loop(d_dinner, ph);

//	i =0;
//	while(i < ph->d_dinner->num_ph)
//	{
//		printf("in join %lu\n", ph[i].th);
//		if (pthread_join(ph[i].th, NULL))
//			printf("not loop join\n");
//		i++;
//	}

	i = 0;
	while (i < d_dinner->num_ph)
	{
		if (pthread_mutex_destroy(&ph->fork[i]))
			printf("not destroy fork\n");
		i++;
	}
	self = pthread_self();
	printf("self = %lu\n", self);
	if (pthread_mutex_destroy(&ph->message))
		printf("message not destroy\n");
	free(ph->fork);
	free(ph);
	printf("here\n");
}
