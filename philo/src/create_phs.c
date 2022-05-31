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
		my_sleep(ph_tmp->d_dinner.tt_eat); //
//		my_sleep(50);
	while (ph_tmp->d_dinner.flag != 1 &&  ph_tmp->count_eat != ph_tmp->d_dinner.num_must_eat) // &&ph_tmp->eat_all!= 1
		// ph_tmp->count_eat != ph_tmp->d_dinner.num_must_eat &&
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
		printf("check\n");
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
		//ph[i].died = &ph->flag;
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
		if (ph[i].th == 0)
			printf(" ooops th = 0\n");
		printf("ph %d th = %ld\n", ph[i].num, (pthread_t)ph[i].th);
		//pthread_detach(ph[i].th);
		//pthread_join(ph[i].th, NULL);
		i++;
	}
	usleep(100); // was 100
	ph_died(ph);
//	i = 0;
//	while (i < d_dinner->num_ph)
//	{
//		pthread_join(thread[i], NULL);
//		i++;
//	}
	return ;
}

void create_phs(t_data *d_dinner)
{
	t_philo	*ph;
	int		i;

	i = 0;
//	if (malloc_data(ph, d_dinner))
//		printf("malloc check\n");
	ph = (t_philo *)malloc(d_dinner->num_ph * sizeof(t_philo));
	ph->fork = (pthread_mutex_t *)malloc((d_dinner->num_ph) * sizeof(pthread_mutex_t));

	if (pthread_mutex_init(&ph->message, NULL))
		printf("not init message\n");
	d_dinner->begin_time = get_time();
	//print(d_dinner);
	create_loop(d_dinner, ph);
//	if (d_dinner->num_ph == 1)
//	{
//		//exit(0);
//		printf("th %d = %ld\n", i, thread[i]);
//		if (pthread_join(thread[i], NULL) != 0)
//			printf("1 not joined\n");
//		//pthread_join(thread[0], NULL);
//
//		free(ph->th);
//		free(ph->fork);
//		free(ph);
//		return ;
//	}
	printf("before test\n");
//	while (i < d_dinner->num_ph)
//	{
//		printf ("thread %d  = %ld\n", i, ph[i].th);
//		pthread_join(ph[i].th, NULL);
//		i++;
//	}
	while (i < d_dinner->num_ph)
	{
		printf ("thread %d  = %ld\n", i, ph[i].th);
		i++;
	}
	i = 0;

	while (i < d_dinner->num_ph)
	{
		//printf("fork %d = %d\n", i, &ph->fork[i]);
		if (pthread_mutex_destroy(&ph->fork[i]) != 0)
			printf("not destroy fork\n");
		i++;
	}
	i = 0;
	printf("after destroy\n");
	pthread_join(ph[i].th, NULL);
//	//pthread_detach(ph[i].th);
	while (i < d_dinner->num_ph)
	{
		if (pthread_join(ph[i].th, NULL))
			printf("not joined\n");
		i++;
		printf("after i++\n");
	}
	printf("test\n");
	if (pthread_mutex_destroy(&ph->message) != 0)
		printf("message not destroy\n");
	//free(ph.th);
	free(ph->fork);
	free(ph);
	//usleep(1000);
}
