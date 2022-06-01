//
// Created by user on 08.05.22.
//

#include "../inc/philo.h"

void	print(t_data *d_dinner)
{
	printf(GREEN"num of philo %d\n"NC, d_dinner->num_ph);
	printf(RED"time to die %d\n"NC, d_dinner->tt_die);
	printf("time to eat %d\n", d_dinner->tt_eat);
	printf("time to sleep %d\n", d_dinner->tt_sleep);
	printf(YELLOW"time to must eat %d\n"NC, d_dinner->num_must_eat);
	printf("begin time = %ld\n", d_dinner->begin_time);
	printf("start\n");
}

void	print_put(t_philo *ph_tmp, int c)
{
	pthread_mutex_lock(&ph_tmp->message);
	if (c == 11)
	{
		printf("%d %d ph PUT left_fork %p\n", passed_time
		(ph_tmp->d_dinner->begin_time), ph_tmp->num,ph_tmp->left_fork);
		pthread_mutex_unlock(&ph_tmp->message);
	}
	else if (c == 12)
	{
		printf("%d %d ph PUT right_fork %p\n", passed_time
		(ph_tmp->d_dinner->begin_time), ph_tmp->num, ph_tmp->right_fork);
		pthread_mutex_unlock(&ph_tmp->message);
	}

}