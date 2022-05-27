

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

// * STRUCT DATA * //

typedef struct s_data
{
	int		*pid;
	int		id_ph;
	int		nbr_philo;
	int		tt_die;
	int		tt_eat;
	int		tt_sleep;
	int		must_eat;
	int		start_time;
	int		time_left;
	sem_t	*sem_die;
	sem_t	*sem_print;
	sem_t	*sem_fork;
	sem_t	*sem_odd;
}				t_data;

// * PROCESSES UTILS * //

//void	ft_kill_child(t_data *data, int def);
//void	ft_sem_close(t_data *data, int def);
void	ft_check_dead(t_data *data);
void	ft_meal_check(t_data *data);
void	ft_child_set(t_data *data);

// * UTILS * //

void	ft_write_sms(t_data *data, char *str);
int		ft_define_args(int argc, char **argv, t_data *data);
void	ft_process_init(t_data *data);
int		ft_atoi(const char *str);

// * TIME UTILS * //

int		ft_get_time(void);
void	ft_usleep(t_data *data, int sleep);

#endif