cmake_minimum_required(VERSION 3.21)
project(philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(philosophers philo/src/philo.c
		philo/src/ft_atoi.c)
		#training/learncinfo1.c)
		#training/codevault.c)
