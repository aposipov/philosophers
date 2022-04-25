//
// Created by user on 25.04.22.
//

#include "../inc/philo.h"

long int get_time(void)
{
	struct timeval t_start;

	gettimeofday(&t_start, NULL);
	return (t_start.tv_sec * 1000 + t_start.tv_usec / 1000);
}

void	my_sleep(int ms)
{
	long	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(50);
}