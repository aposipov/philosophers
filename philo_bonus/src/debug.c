//
// Created by user on 31.05.22.
//

#include "../inc/philo_bonus.h"

void	print(t_philo *lunch)
{
	printf(GREEN"num of philo %d\n"NC, lunch->num_ph);
	printf(RED"time to die %d\n"NC, lunch->tt_die);
	printf("time to eat %d\n", lunch->tt_eat);
	printf("time to sleep %d\n", lunch->tt_sleep);
	printf(YELLOW"time to must eat %d\n"NC, lunch->num_must_eat);
	printf("begin time = %ld\n", lunch->time_start);
	printf("start\n");
}
