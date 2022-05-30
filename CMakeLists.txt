cmake_minimum_required(VERSION 3.21)
project(philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(philosophers
		philo/src/philo.c
		philo/src/ft_atoi.c
		philo/src/create_phs.c
		philo/src/time.c
		philo/src/ph_do.c
		philo/src/print_log.c
		philo/src/debug.c
		philo/src/utils.c)

#add_executable(philosophers
#		philo_bonus/src/philo_bonus.c
#		philo_bonus/src/utils.c
#		philo_bonus/src/time.c
#		philo_bonus/src/process.c)

#add_executable(philosophers training/test.c
#		training/test2.c)