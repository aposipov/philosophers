

NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = ./inc/philo.h

SRCS =	./src/philo.c

OBJ = $(patsubst %.c, %.o, $(SRCS))

RED='\033[4;31m'
GREEN= '\033[0;32m'
NC='\033[0;0m'

.PHONY:	all clean fclean re norm libft

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(libft_) -o $(NAME)
			@echo -e $(GREEN)Philo compiled!$(NC)

%.o : %.c 	Makefile $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)
			@echo -e $(RED) *.o files is clean!$(NC)

fclean:		clean
			rm -f $(NAME)
			@echo -e $(RED)All files is clean!$(NC)

re:			fclean all

norm:
			@norminette $(HEADER) $(SRCS)