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

void	*philosoph(void *ph)
{
	t_philo	*ph_tmp;

	ph_tmp = ph;
	if (ph_tmp->num % 2 == 0)
		//usleep(50);
		my_sleep((ph_tmp->d_dinner.tt_eat)); //
	while (*ph_tmp->died != 1 && ph_tmp->count_eat != ph_tmp->d_dinner.num_must_eat)
	{
		pthread_mutex_lock(ph_tmp->left_fork);
		if (print_log(ph_tmp, 11))
			return (NULL);
		//printf("%d %d ph take left_fork %d\n", passed_time(ph_tmp->d_dinner.begin_time), ph_tmp->num, ph_tmp->left_fork);
		pthread_mutex_lock(ph_tmp->right_fork);
		if (print_log(ph_tmp, 12))
			return (NULL);
		//printf("%d %d ph take right_fork %d\n", passed_time(ph_tmp->d_dinner.begin_time), ph_tmp->num, ph_tmp->right_fork);

		ph_eats(ph_tmp);
		//printf("%d %d ph PUT left_fork %d\n", passed_time(ph_tmp->d_dinner.begin_time), ph_tmp->num, ph_tmp->left_fork);
		pthread_mutex_unlock(ph_tmp->right_fork);
		pthread_mutex_unlock(ph_tmp->left_fork);
		//printf("%d %d ph PUT right_fork %d\n", passed_time(ph_tmp->d_dinner.begin_time), ph_tmp->num, ph_tmp->right_fork);
		ph_sleeps(ph_tmp);
		ph_thinks(ph_tmp);
	}
	return (NULL);
}

static void	create_loop(t_data *d_dinner, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < d_dinner->num_ph)
	{
		pthread_mutex_init(&ph->fork[i], NULL);
		ph[i].d_dinner = *d_dinner;
		//ph[i].d_dinner.begin_time = get_time();
		ph[i].num = i + 1;
		ph[i].right_fork = &ph->fork[i];
		ph[i].last_eat = 0;
		ph[i].count_eat = 0;
		ph[i].died = &ph->flag;
		if (i != d_dinner->num_ph - 1) //
			ph[i].left_fork = &ph->fork[i + 1];
		else
			ph[i].left_fork = &ph->fork[0];
		pthread_create(&ph->th[i], NULL, &philosoph, (void *)(&ph[i]));
		i++;
	}
	usleep(100);
	ph_died(ph);
	//pthread_create(&ph->th[i], NULL, &ph_died, (void *)(ph));
}

void create_phs(t_data *d_dinner)
{
	t_philo	*ph;
	int		i;

	i = 0;

	ph = (t_philo *)malloc(d_dinner->num_ph * sizeof(t_philo));
	ph->th = (pthread_t *)malloc((d_dinner->num_ph + 1) * (sizeof(pthread_t)));
	ph->fork = (pthread_mutex_t *)malloc((d_dinner->num_ph) * sizeof
			(pthread_mutex_t));

	pthread_mutex_init(&ph->message, NULL);
	d_dinner->begin_time = get_time();
	print(d_dinner);
	//usleep(1000000);
	create_loop(d_dinner, ph);
	i = 0;
	while (i < d_dinner->num_ph)
		pthread_mutex_destroy(&ph->fork[i++]);
	i = 0;
	//while (i < d_dinner->num_ph)
	pthread_join(ph->th[i], NULL);
	pthread_mutex_destroy(&ph->message);
	free(ph->th);
	free(ph->fork);
	free(ph);
}
