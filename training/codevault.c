//
// Created by user on 15.04.2022.
//

//#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *routine()
{
	printf("Test from threads!\n");
	sleep(1);
	printf("Ending thread!\n");
}

int main(int argc, char **argv)
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, &routine, NULL);
	printf("t1 = %d\n", t1);
	pthread_create(&t2, NULL, &routine, NULL);
	printf("t2 = %d\n", t2);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
