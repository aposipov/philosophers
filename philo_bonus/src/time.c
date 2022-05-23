//
// Created by user on 22.05.22.
//

#include "../inc/philo_bonus.h"

int	ft_get_time(void)
{
	static struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * (u_int64_t)1000) + (tm.tv_usec / 1000));
}

void	ft_usleep(t_data *data, int sleep)
{
	long int	start_time;

	start_time = ft_get_time();
	while ((ft_get_time() - start_time) < sleep)
	{
		ft_check_dead(data);
		usleep((sleep % 100) + 1);
	}
}