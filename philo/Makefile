

NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAG1 = -fsanitize=thread
FLAG2 = -pthread
HEADER = ./inc/philo.h

SRCS =	./src/philo.c\
		./src/create_phs.c\
		./src/debug.c\
		./src/ph_do.c\
		./src/print_log.c\
		./src/time.c\
		./src/utils.c\

OBJ = $(patsubst %.c, %.o, $(SRCS))

RED= \033[4;31m
GREEN= \033[0;32m
NC= \033[0;0m

.PHONY:	all clean fclean re norm

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			@echo -e "$(GREEN)\t\n Philo compiled! \n $(NC)"

%.o : %.c 	Makefile $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)
			@echo -e "$(RED)*.o files is clean!$(NC)"

fclean:		clean
			rm -f $(NAME)
			@echo -e "$(RED)All files is clean!$(NC)"

re:			fclean all

norm:
			@norminette $(HEADER) $(SRCS)
