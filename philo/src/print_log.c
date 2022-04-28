//
// Created by user on 28.04.22.
//

#include "../inc/philo.h"

void print_log(t_philo *ph_tmp, int n)
{
	pthread_mutex_lock(&ph_tmp->message);
	if (n == 11)
		printf("%d %d ph take left_fork %d\n", passed_time(ph_tmp->d_dinner
		.begin_time), ph_tmp->num, ph_tmp->left_fork);
	else if (n == 12)
		printf("%d %d ph take right_fork %d\n", passed_time(ph_tmp->d_dinner
		.begin_time), ph_tmp->num, ph_tmp->right_fork);
	else if (n == 1)
		printf(GREEN"%d ph %d is eating\n"NC, passed_time(ph_tmp->d_dinner
		.begin_time),ph_tmp->num);
	else if (n == 2)
		printf(BLUE"%d ph %d is sleeping\n"NC, passed_time(ph_tmp->d_dinner
		.begin_time), ph_tmp->num);
	else if (n == 3)
		printf(CYAN"%d ph %d is thinking\n"NC, passed_time(ph_tmp->d_dinner
		.begin_time), ph_tmp->num);
	else if (n == 4)
		printf(DC"%d PH is DIED!\n"NC, ph_tmp->num);
	pthread_mutex_unlock(&ph_tmp->message);
}