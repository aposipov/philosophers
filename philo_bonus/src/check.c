//
// Created by user on 31.05.22.
//

#include "../inc/philo_bonus.h"

int check_input(int argc, char **argv)
{
	if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[1]) > 200)
	{
		printf(RED"ph must be more than 0 but less 200\n"NC);
		return(1);
	}
	else if (argc == 6  && ft_atoi(argv[5]) == 0)
	{
		printf(RED"time must eat more tnan 0\n"NC);
		return (1);
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

int check_arg(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 5 || argc >6)
	{
		printf(RED"Input 5 or 6 arguments!\n"NC);
		return (1);
	}
	while (argv[i] != NULL)
	{
		if (check_digit(argv[i]) == -1)
		{
			printf(RED"Check your arguments!\n"NC);
			return (1);
		}
		i++;
	}
	if (check_input(argc, argv))
		return (1);
	return (0);
}