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

int valid_input(t_data *d_dinner)
{
	if (d_dinner->num_ph == 0)
	{
		printf(RED"ph must be more than 0\n"NC);
		return(-1);
	}
	if (d_dinner->num_must_eat == 0)
	{
		printf(RED"time must eat more tnan 0\n"NC);
		return (-1);
	}
	return (0);
}

int check_digit(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int check_arg(char **argv)
{
	int i = 1;

	while (argv[i] != NULL)
	{
		if (check_digit(argv[i]) == -1)
		{
			printf(RED"Check your arguments!\n"NC);
			return (-1);
		}
		i++;
	}
	return (0);
}

void init_input(int argc, char **argv, t_data *d_dinner)
{
	d_dinner->num_ph = ft_atoi(argv[1]);
	d_dinner->tt_die = ft_atoi(argv[2]);
	d_dinner->tt_eat = ft_atoi(argv[3]);
	d_dinner->tt_sleep = ft_atoi(argv[4]);
	d_dinner->begin_time = 0;
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
	if (check_arg(argv) == -1)
		return (0);
	init_input(argc, argv, &d_dinner);
	// valid input
	if (valid_input(&d_dinner) == -1)
		return (0);
	print(&d_dinner);
	create_phs(&d_dinner);
	//printf("the end!\n");
	return (0);
}
