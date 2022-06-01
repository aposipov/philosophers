//
// Created by user on 22.05.22.
//

#include "../inc/philo_bonus.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	old;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' \
					|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		old = num;
		num = num * 10 + (nptr[i++] - '0');
		if ((old < 0 && num > 0) || (old > 0 && num < 0))
			return ((sign == 1) * -1);
	}
	return (int)(num * sign);
}

void	all_free(t_philo *lunch)
{
	sem_unlink("print");
	sem_unlink("fork");
	sem_close(lunch->s_print);
	sem_close(lunch->s_fork);
	free(lunch->pid);
}

int	all_kill(t_philo *lunch)
{
	int	i;

	i = -1;
	while (++i < lunch->num_ph)
		kill(lunch->pid[i], SIGKILL);
	return (0);
}