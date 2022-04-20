

#include <stdio.h>

int main(int argc, char **argv)
{
	char *philos = argv[1];
	char *time_eat = argv[2];
	char *time_sleep = argv[3];

	printf("Hello, Philo!\n");
	if (argc < 4 || argc >6)
		printf("check arguments");

	printf("%s\n", argv[0] );
	printf("philos = %s\n", philos );
	printf("time to eat = %s\n", time_eat );
	printf("time to sleep = %s\n", time_sleep );


	return 0;
}