//
// Created by user on 17.04.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static int counter = 0;
static int counter2 = 0;

void *plus()
{
	int local;

	local = counter2;
	printf("plus=%d\n", counter2);
	local = local + 1;
	counter2 = local;
	return NULL;
}

void *minus()
{
	int local;

	local = counter;
	printf("minus=%d\n", counter);
	local = local - 1;
	counter = local;
	//sleep(5);
	return NULL;
}

#define NUM_OF_THREADS 100

int main()
{
	pthread_t threads[NUM_OF_THREADS];
	size_t i = 0;

	printf("counter-=%d\n", counter);
	printf("counter+=%d\n", counter2);
	while (i < NUM_OF_THREADS/2)
	{
		pthread_create(&threads[i], NULL, minus, NULL);
		i++;
		//printf("min_i=%d", i);
	}
	while (i < NUM_OF_THREADS)
	{
		pthread_create(&threads[i], NULL, plus, NULL);
		i++;
	}
	while (i < NUM_OF_THREADS)
	{
		i = 0;
		pthread_join(threads[i], NULL);
		i++;
	}
	printf("counter- = %d\n", counter);
	printf("counter+ = %d\n", counter2);
	return 0;

}

//#include <stdio.h>
//#include <stdlib.h>
//#include <pthread.h>
//
//static int counter = 0;
//
//void* minus(void *args) {
//	int local;
//
//	local = counter;
//	printf("min %d\n", counter);
//	local = local - 1;
//	counter = local;
//	return NULL;
//}
//
//void* plus(void *args) {
//	int local;
//
//	local = counter;
//	printf("pls %d\n", counter);
//	local = local + 1;
//	counter = local;
//	return NULL;
//}
//
//#define NUM_OF_THREADS 100
//
//int main() {
//	pthread_t threads[NUM_OF_THREADS];
//	size_t i;
//
//	printf("counter = %d\n", counter);
//	for (i = 0; i < NUM_OF_THREADS/2; i++) {
//		pthread_create(&threads[i], NULL, minus, NULL);
//	}
//	for (; i < NUM_OF_THREADS; i++) {
//		pthread_create(&threads[i], NULL, plus, NULL);
//	}
//	for (i = 0; i < NUM_OF_THREADS; i++) {
//		pthread_join(threads[i], NULL);
//	}
//	printf("counter = %d", counter);
//	return 0;
//}