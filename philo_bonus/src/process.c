//
// Created by user on 22.05.22.
//

#include "../inc/philo_bonus.h"

void	ft_check_dead(t_data *data)
{
	if (ft_get_time() - data->time_left >= data->tt_die)
	{
		ft_write_sms(data, "DIED");
		//sem_wait(data->sem_print);
		sem_post(data->sem_die);
		free(data->pid);
		exit (1);
	}
}

void	ft_meal_check(t_data *data)
{
	static int	meal;

	if (meal == data->must_eat - 1)
	{
		free(data->pid);
		exit (0);
	}
	else if (meal < data->must_eat)
		meal += 1;
}

void	ft_child_set2(t_data *data)
{
	ft_meal_check(data);
	ft_check_dead(data);
	ft_write_sms(data, "is sleeping");
	ft_usleep(data, data->tt_sleep);
	ft_check_dead(data);
	ft_write_sms(data, "is thinking");
}

void	ft_child_set(t_data *data)
{
	while (1)
	{
		ft_check_dead(data);
		sem_wait(data->sem_odd);
		sem_wait(data->sem_fork);
		ft_write_sms(data, "is taking the left fork");
		if ((ft_get_time() - data->time_left) + data->tt_eat
			>= data->tt_die && data->nbr_philo % 2 == 1)
			ft_usleep(data,
					  (ft_get_time() - data->time_left) + data->tt_eat + 1);
		if (data->nbr_philo == 1)
			ft_usleep(data, data->tt_die + 1);
		sem_wait(data->sem_fork);
		ft_check_dead(data);
		ft_write_sms(data, "is taking the right fork");
		sem_post(data->sem_odd);
		data->time_left = ft_get_time();
		ft_write_sms(data, "is eating");
		ft_usleep(data, data->tt_eat);
		sem_post(data->sem_fork);
		sem_post(data->sem_fork);
		ft_child_set2(data);
	}
}

void	ft_process_init(t_data *data)
{
	int		i;

	i = 0;
	data->pid = (int *) malloc (sizeof(int) * data->nbr_philo);
	if (!data->pid)
		exit(1);
	while (i < data->nbr_philo)
	{
		if (i == 0 || data->pid[i - 1] != 0)
		{
			data->pid[i] = fork();
			if (data->pid[i] == 0)
			{
				data->id_ph = i + 1;
				ft_child_set(data);
			}
		}
		i++;
	}
}