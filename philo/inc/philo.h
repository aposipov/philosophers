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

# define ms 1000

typedef struct s_data{
	int				num_phil;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_must_eat;
	struct timeval	start;
}	t_data;

typedef struct s_philo{
	t_data			data;
	pthread_t		*th;
	pthread_mutex_t mutex;
	int 			n;
	//pthread_mutex_t	*left_fork;
	//pthread_mutex_t	*right_fork;
}	t_philo;

int	ft_atoi(const char *str);

#endif
