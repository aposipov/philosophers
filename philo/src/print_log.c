//
// Created by user on 28.04.22.
//

#include "../inc/philo.h"

void print_take(t_philo *ph_tmp, int c) // debug
{
	pthread_mutex_lock(&ph_tmp->message);
	if (c == 11)
		printf("%d %d ph take left_fork %p\n", passed_time(ph_tmp->d_dinner.begin_time), ph_tmp->num, ph_tmp->left_fork);
	else if (c == 12)
		printf("%d %d ph take right_fork %p\n", passed_time(ph_tmp->d_dinner.begin_time), ph_tmp->num, ph_tmp->right_fork);
}

int print_log(t_philo *ph_tmp, int n)
{
	int time;

	pthread_mutex_lock(&ph_tmp->message);
	if (n == 4)
	{
		time = passed_time(ph_tmp->d_dinner.begin_time) - ph_tmp->last_eat;
		printf(RED"%d %d ph passed time = %d\n"NC, passed_time
		(ph_tmp->d_dinner.begin_time), ph_tmp->num, time);
		printf(RED"%d PH is DIED! FLAG = %d\n"NC, ph_tmp->num, *ph_tmp->died);
		//pthread_detach(*ph_tmp->th);
		pthread_mutex_unlock(&ph_tmp->message);
		return (0);
	}
	else if ( n == 5)
	{
		printf("all eat!\n");
		pthread_mutex_unlock(&ph_tmp->message);
		usleep (1000);
		return (0);
	}
//	else if ((*ph_tmp).died == 1)
//	{
//		pthread_mutex_unlock(&ph_tmp->message);
//		return ;
//	}
	else if (n == 11  && *ph_tmp->died != 1)
		printf("%d %d ph take left_fork %p\n", passed_time(ph_tmp->d_dinner.begin_time), ph_tmp->num, ph_tmp->left_fork);
	else if (n == 12 && *ph_tmp->died != 1)
		printf("%d %d ph take right_fork %p\n", passed_time(ph_tmp->d_dinner.begin_time), ph_tmp->num, ph_tmp->right_fork);
	else if (n == 1)
	{
		printf(GREEN"%d ph %d is eating\n"NC, passed_time(ph_tmp->d_dinner.begin_time),ph_tmp->num);
		printf(MAGENTA"ph %d eat count = %d; flag died = %d\n"NC,
			   ph_tmp->num, ph_tmp->count_eat + 1, *ph_tmp->died);
		//printf(MAGENTA"ph %d adr_flag = %p\n"NC, ph_tmp->num, &ph_tmp->flag);
		//printf(MAGENTA"ph %d adr_died = %p\n"NC, ph_tmp->num, ph_tmp->died);
	}
	else if (n == 2)
		printf(BLUE"%d ph %d is sleeping\n"NC, passed_time(ph_tmp->d_dinner.begin_time), ph_tmp->num);
	else if (n == 3)
		printf(CYAN"%d ph %d is thinking\n"NC, passed_time(ph_tmp->d_dinner.begin_time), ph_tmp->num);
	pthread_mutex_unlock(&ph_tmp->message);
	return (0);
}

