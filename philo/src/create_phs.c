

#include "../inc/philo.h"

void	*philosoph(void *tmp)
{
	t_philo	*ph;

	ph = tmp;
	if (ph->num % 2 == 0)
		my_sleep((int)ph->d_dinner->tt_eat); //
	while (ph->d_dinner->died != 1 && ph->count_eat != ph->d_dinner->num_must_eat)
	{
		pthread_mutex_lock(ph->left_fork);
		//if (print_on_screen(philo, 1))
		//	return (NULL);
		printf("%d ph take left_fork\n", ph->num);
		pthread_mutex_lock(ph->right_fork);
		//if (print_on_screen(philo, 2))
		//	return (NULL);
		printf("%d ph take right_fork\n", ph->num);
		//ph_eating(ph);
		pthread_mutex_unlock(ph->left_fork);
		pthread_mutex_unlock(ph->right_fork);
		//ph_sleeping(ph);
		//ph_thinking(ph);
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
		ph[i].d_dinner = d_dinner;
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
	//pthread_create(&th[i], NULL, &die, (void *)(ph));
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
	printf("begin time = %ld\n", d_dinner->begin_time);
	print(d_dinner);
	usleep(1000000);
	//if (d_dinner->num_ph <= 0)
	//	return ;
	create_cycle(d_dinner, ph, th);
	while (i < d_dinner->num_ph)
		pthread_mutex_destroy(&d_dinner->mutex[i++]);
	i = 0;
	while (i < d_dinner->num_ph)
		pthread_join(th[i], NULL);
	pthread_mutex_destroy(&d_dinner->message);
//	free(thread);
//	free(data->mutex);
//	free(philo);
}