/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:02:51 by lchristi          #+#    #+#             */
/*   Updated: 2022/04/21 13:03:01 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define NC			"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define DC			"\033[41m"

typedef struct s_data{
	int				num_ph;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				num_must_eat;
	long int		begin_time;
}	t_data;

typedef struct s_philo{
	int				num;
	int				count_eat;
	int				*died;
	int				flag;
	int				last_eat;
	int 			eat_all;
	pthread_t		*th;
	pthread_mutex_t	*fork;
	pthread_mutex_t	message;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			d_dinner;
}	t_philo;

//print log
int			print_log(t_philo *ph_tmp, int c);
int			ft_atoi(const char *str);

void		create_phs(t_data *d_dinner);

//time
long int	get_time(void);
void		my_sleep(int ms);
int			passed_time(long int begin_time);

//ph do
void		ph_eats(t_philo *ph);
void		ph_sleeps(t_philo *ph);
void		ph_thinks(t_philo *ph);
void		ph_died(t_philo *ph);

//debug
void		print(t_data *d_dinner);
void		print_put(t_philo *ph_tmp, int c);

#endif
