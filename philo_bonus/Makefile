

NAME = philo_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAG1 = -fsanitize=thread
FLAG2 = -pthread
HEADER = ./inc/philo_bonus.h

SRCS =	./src/philo_bonus.c\
		./src/ft_atoi.c\

OBJ = $(patsubst %.c, %.o, $(SRCS))

RED= \033[4;31m
GREEN= \033[0;32m
NC= \033[0;0m

.PHONY:	all clean fclean re launch norm check

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

launch:		$(OBJ)
			@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			./philo 3 205 100 100

norm:
			@norminette $(HEADER) $(SRCS)

check:		$(OBJ)
			$(CC) $(FLAGS) $(FLAG1) $(OBJ) -o $(NAME)
			./philo 3 205 100 100