//
// Created by user on 22.05.22.
//

#include "../inc/philo_bonus.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday (&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	my_sleep(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(1); // was 100
}