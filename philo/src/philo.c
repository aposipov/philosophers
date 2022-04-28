/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:15:15 by lchristi          #+#    #+#             */
/*   Updated: 2022/04/26 21:15:22 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print(t_data *d_dinner)
{
	printf(GREEN"num of philo %d\n"NC, d_dinner->num_ph);
	printf(RED"time to die %d\n"NC, d_dinner->tt_die);
	printf("time to eat %d\n", d_dinner->tt_eat);
	printf("time to sleep %d\n", d_dinner->tt_sleep);
	printf(YELLOW"time to must eat %d\n"NC, d_dinner->num_must_eat);
	printf(RED"dead %d\n"NC, d_dinner->died);
	printf("begin time = %ld\n", d_dinner->begin_time);
	printf("ok\n");

	//return(0);
}

int check_arg(int argc, char **argv)
{
	if (ft_atoi(argv[1]) == -1)
		return (-1);
}

void init_input(int argc, char **argv, t_data *d_dinner)
{
	d_dinner->num_ph = ft_atoi(argv[1]);
	d_dinner->tt_die = ft_atoi(argv[2]);
	d_dinner->tt_eat = ft_atoi(argv[3]);
	d_dinner->tt_sleep = ft_atoi(argv[4]);
	d_dinner->begin_time = 0;
	//d_dinner->died = 0;
	if (argc == 6)
		d_dinner->num_must_eat = ft_atoi(argv[5]);
	else
		d_dinner->num_must_eat = -1;
}

int main(int argc, char **argv)
{
	t_data	d_dinner;

	if (argc < 5 || argc >6)
	{
		printf(RED"Input 5 or 6 arguments!"NC);
		return (0);
	}
	// check_argc char and negative
//	if (check_arg(argc, argv) == -1)
//		return (0);
	init_input(argc, argv, &d_dinner);
	print(&d_dinner);
	create_phs(&d_dinner);
	printf("end\n");
	return (0);
}
