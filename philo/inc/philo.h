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

//# define ms 1000

typedef struct s_data{
	int				num_ph;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				num_must_eat;
	int 			died;
	long int		begin_time;
	pthread_mutex_t *mutex;
	pthread_mutex_t message; //
	//struct timeval	start;
}	t_data;

typedef struct s_philo{
	int				num;
	int 			count_eat;
	int 			last_eat;
	pthread_t		th;
	pthread_mutex_t mutex;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*d_dinner;
}	t_philo;

void print(t_data *);

int	ft_atoi(const char *);


void create_phs(t_data *);

//time
long int	get_time(void);
void	my_sleep(int ms);



#endif
