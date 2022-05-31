//
// Created by user on 22.05.22.
//
#include "../inc/philo_bonus.h"

void	*death_monitor(void *lunch)
{
	t_philo	*tmp;

	tmp = (t_philo *)lunch;
	while (1)
	{
		if (tmp->num_must_eat)
			if (tmp->num_philo_eat == tmp->num_must_eat)
				break ;
		if (get_time() - tmp->time_last_eat > tmp->tt_die)
		{
			tmp->flag_d = 1;
			sem_wait(tmp->s_print);
			printf(RED"%lld %d is died\n"NC, get_time() - tmp->time_start,
			tmp->name_ph);
			break ;
		}
	}
	if (tmp->flag_d)
		exit (1);
	else
		exit (0);
}

void	print_log(t_philo *lunch, char *str)
{
	sem_wait(lunch->s_print);
	printf("%lld %d %s\n",get_time() - lunch->time_start, lunch->name_ph, str);
	sem_post(lunch->s_print);
}

int	eat_sleep_think(t_philo *lunch)
{
	sem_wait(lunch->s_fork);
	print_log(lunch, "has taken a fork");
	if (lunch->num_ph == 1)
		return (sem_post(lunch->s_fork), 1); //
	sem_wait(lunch->s_fork);
	print_log(lunch, "has taken a fork");
	print_log(lunch, "is eating");
	lunch->time_last_eat = get_time();
	my_sleep(lunch->tt_eat);
	sem_post(lunch->s_fork);
	sem_post(lunch->s_fork);
	lunch->num_philo_eat++;
	print_log(lunch, "is sleeping");
	my_sleep(lunch->tt_sleep);
	print_log(lunch, "is thinking");
	return (0);
}

int	killer(t_philo *lunch)
{
	int	i;

	i = -1;
	while (++i < lunch->num_ph)
		kill(lunch->pid[i], SIGKILL);
	return (0);
}

int	philo_lunch(t_philo *lunch)
{
	if (pthread_create(&lunch->t_monitor, NULL, &death_monitor, lunch))
		return (1);
	if (lunch->name_ph % 2 == 1)
		usleep(lunch->tt_eat);
	while (1)
	{
		if (lunch->num_must_eat)
			if (lunch->num_philo_eat == lunch->num_must_eat)
				break ;
		if (eat_sleep_think(lunch))
			break ;
	}
	if (pthread_join(lunch->t_monitor, NULL))
		return (1); // exit
	return (0);
}

int	start_lunch(t_philo *lunch)
{
	int	i;
	int	status;

	i = -1;
	lunch->time_start = get_time();
	while (++i < lunch->num_ph)
	{
		lunch->pid[i] = fork();
		if (lunch->pid[i] == -1)
			return (1); // exit
		if (lunch->pid[i] == 0)
		{
			lunch->name_ph = i + 1;
			lunch->time_last_eat = lunch->time_start;
			if (philo_lunch(lunch)) //
				return (1); // exit
		}
	}
	waitpid(-1, &status, 0);
//	while (waitpid(-1, &status, 0) > 0)
//	{
//		if (WEXITSTATUS(status) == 1)
//			return (killer(lunch));
//	}
	return (0);
}