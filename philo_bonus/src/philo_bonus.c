//
// Created by user on 22.05.22.
//

#include "../inc/philo_bonus.h"

void	ft_sem_close(t_data *data, int def)
{
	sem_close(data->sem_die);
	sem_close(data->sem_fork);
	sem_close(data->sem_write);
	sem_close(data->sem_odd);
	if (def == 1)
		free(data->pid);
}

void	ft_kill_child(t_data *data, int def)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		kill(data->pid[i], SIGKILL);
		i++;
	}
	ft_sem_close(data, def);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		stat;
	int		i;

	i = 0;
	stat = 0;
	if (argc != 6 && argc != 5)
		exit(write(2, "Invalid arguments. Exit", 24));
	ft_define_args(argc, argv, &data);
	if (data.must_eat > 0)
	{
		while (i++ < data.nbr_philo)
		{
			waitpid(-1, &stat, 0);
			if (stat != 0)
			{
				ft_kill_child(&data, -1);
				return (0);
			}
		}
		return (0);
	}
	sem_wait(data.sem_die);
	ft_kill_child(&data, 1);
	return (0);
}