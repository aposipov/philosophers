//
// Created by user on 22.05.22.
//

#include "../inc/philo_bonus.h"

void	ft_write_sms(t_data *data, char *str)
{
	sem_wait(data->sem_print);
	printf("%d ms %d %s\n", ft_get_time() - data->start_time,
		   data->id_ph, str);
	sem_post(data->sem_print);
}

int	ft_define_args(int argc, char **argv, t_data *data)
{
	data->id_ph = 0;
	data->nbr_philo = ft_atoi(argv[1]);
	data->tt_die = ft_atoi(argv[2]);
	data->tt_eat = ft_atoi(argv[3]);
	data->tt_sleep = ft_atoi(argv[4]);
	data->start_time = ft_get_time();
	data->time_left = data->start_time;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	if (data->nbr_philo <= 0 || data->tt_die <= 0 || data->tt_eat <= 0
		|| data->tt_sleep <= 0 || data->must_eat < -1)
		exit(write(2, "Invalid arguments. Exit", 24));
	sem_unlink("sem_die");
	sem_unlink("sem_fork");
	sem_unlink("sem_write");
	sem_unlink("sem_odd");
	data->sem_die = sem_open("sem_die", O_CREAT, 0644, 0);
	data->sem_odd = sem_open("sem_odd", O_CREAT, 0644, 1);
	data->sem_fork = sem_open("sem_fork", O_CREAT, 0644, data->nbr_philo);
	data->sem_print = sem_open("sem_write", O_CREAT, 0644, 1);
	ft_process_init(data);
	return (0);
}

int	ft_isdigit(int c) // change
{
	if (c > 57 || c < 48)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)  // change
{
	int	y;
	int	j;

	y = 0;
	j = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 43)
		return (-1);
	while (*str)
	{
		if (!ft_isdigit(*str) || j > 11
			|| (j == 10 && y > 214748364))
			return (-1);
		y = (y * 10) + ((*str - 48) % 10);
		str++;
		j++;
	}
	return (y);
}