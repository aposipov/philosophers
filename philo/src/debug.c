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