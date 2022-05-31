

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>	// usleep, write, fork
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free, exit
# include <signal.h>	// kill
# include <pthread.h>	// pthread_create
# include <semaphore.h>	// sem_open, sem_close ... sem_unlink
# include <sys/wait.h>	// waitpid
# include <sys/time.h>	// gettimeofday
# include <fcntl.h>
//# include <string.h>	// ??

# define NC			"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define DC			"\033[41m"

typedef struct s_philo
{
	int			num_ph;
	int			tt_die;
	int			tt_eat;
	int			tt_sleep;
	int			num_must_eat;
	int			name_ph;
	int			num_philo_eat;  //
	int			flag_d;
	pid_t		*pid;
	sem_t		*s_print;
	sem_t		*s_fork;
	pthread_t	t_monitor;
	long long	time_start;
	long long	time_last_eat;
}				t_philo;

//typedef struct s_philo
//{
//	int				num_of_philos;
//	int				num_of_forks;
//	long long		time_to_die;
//	int				time_to_eat;
//	int				time_to_sleep;
//	long long		num_must_eat;
//	int				is_limited;
//	unsigned long	start_time;
//	int				number;
//	int				eat_status;
//	int				stop_count;
//	long long		curr_time;
//	long long		last_eat_time;
//	pid_t			process;
//	sem_t			*sem_death;
//	sem_t			*sem_fork;
//	pthread_t		die_detector;
//}	t_philo;

int	start_lunch(t_philo *lunch);
long long	get_time(void);
void	my_sleep(long long time);
void	all_free(t_philo *lunch);

/* check */
int check_arg(int argc, char **argv);

/* utils */
int	ft_atoi(const char *nptr);


/* debug*/
void	print(t_philo *lunch);

#endif