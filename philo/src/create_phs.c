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

void	*philosoph(void *tmp)
{
	t_philo	*ph;

	ph = tmp;
	if (ph->num % 2 == 0)
		my_sleep((int)ph->d_dinner.tt_eat); //
	while (ph->d_dinner.died != 1 && ph->count_eat != ph->d_dinner.num_must_eat)
	{
		pthread_mutex_lock(ph->left_fork);
		//if (print_on_screen(philo, 1))
		//	return (NULL);
		printf("%d %d ph take left_fork\n", passed_time(ph->d_dinner.begin_time),
			   ph->num);
		pthread_mutex_lock(ph->right_fork);
		//if (print_on_screen(philo, 2))
		//	return (NULL);
		printf("%d %d ph take right_fork\n", passed_time(ph->d_dinner.begin_time),ph->num);
		ph_eats(ph);
		pthread_mutex_unlock(ph->left_fork);
		pthread_mutex_unlock(ph->right_fork);
		ph_sleeps(ph);
		ph_thinks(ph);
	}
	return (NULL);
}

static void	create_cycle(t_data *d_dinner, t_philo *ph, pthread_t *th)
{
	int	i;

	i = 0;
	while (i < d_dinner->num_ph)
	{
		pthread_mutex_init(&d_dinner->mutex[i], NULL);
		ph[i].d_dinner = *d_dinner;
		ph[i].num = i + 1;
		ph[i].right_fork = &d_dinner->mutex[i];
		ph[i].last_eat = 0;
		ph[i].count_eat = 0;
		//ph[i].next_d = data;
		//data->next_p = &philo[i];
		if (i != d_dinner->num_ph - 1) //
			ph[i].left_fork = &d_dinner->mutex[i + 1];
		else
			ph[i].left_fork = &d_dinner->mutex[0];
		pthread_create(&th[i], NULL, &philosoph, (void *)(&ph[i]));
		i++;
	}
	usleep(100);
	//pthread_create(&th[i], NULL, &ph_die, (void *)(ph));
}

void create_phs(t_data *d_dinner)
{
	t_philo	*ph;
	pthread_t *th;
	int			i;

	i = 0;

	ph = (t_philo *)malloc(d_dinner->num_ph * sizeof(t_philo));
	th = (pthread_t *)malloc((d_dinner->num_ph + 1) * (sizeof(pthread_t)));
	d_dinner->mutex = (pthread_mutex_t *)malloc((d_dinner->num_ph + 1) * sizeof(pthread_mutex_t));

	pthread_mutex_init(&d_dinner->message, NULL);
	d_dinner->begin_time = get_time();

	//print(d_dinner);
	//usleep(1000000);
	create_cycle(d_dinner, ph, th);
	while (i < d_dinner->num_ph)
		pthread_mutex_destroy(&d_dinner->mutex[i++]);
	i = 0;
	while (i < d_dinner->num_ph)
		pthread_join(th[i], NULL);
	pthread_mutex_destroy(&d_dinner->message);
	free(th);
	free(d_dinner->mutex);
	free(ph);
}
