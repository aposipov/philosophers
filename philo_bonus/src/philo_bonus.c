//
// Created by user on 22.05.22.
//

#include "../inc/philo_bonus.h"

int	init_sp(t_philo *lunch)
{
	sem_unlink("print");
	sem_unlink("fork");
	lunch->s_print = sem_open("print", O_CREAT, 0644, 1);
	if (lunch->s_print == SEM_FAILED)
		return (1); // exit
	lunch->s_fork = sem_open("fork", O_CREAT, 0644, lunch->num_ph);
	if (lunch->s_fork == SEM_FAILED)
		return (1); // exit
	lunch->pid = malloc(sizeof(pid_t) * lunch->num_ph);
	if (!lunch->pid)
	{
		sem_close(lunch->s_print);
		sem_close(lunch->s_fork);
		return (1); // exit
		//return (small_free(all, 3));
	}
	return (0);
}

void	init_data(t_philo *lunch, int argc, char **argv)
{
	lunch->num_ph = ft_atoi(argv[1]);
	lunch->tt_die = ft_atoi(argv[2]);
	lunch->tt_eat = ft_atoi(argv[3]);
	lunch->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		lunch->num_must_eat = ft_atoi(argv[5]);
	else
		lunch->num_must_eat = -1;
	lunch->name_ph = 0;
	lunch->num_philo_eat = 0; //
	lunch->flag_d = 0;
	lunch->time_start = 0;
	lunch->time_last_eat = 0;
}

int	main(int argc, char **argv)
{
	t_philo	lunch;

	if (check_arg(argc, argv))
		return (1);
	init_data(&lunch, argc, argv);

	print(&lunch);
	if (init_sp(&lunch))
		return (1);
	if (start_lunch(&lunch))
		return (1);
	//all_free(lunch);
	printf("the end!\n");
	return (0);
}