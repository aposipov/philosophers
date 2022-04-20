//
// Created by user on 20.04.22.
//

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *print(void *buf)
{
	int i = 0;

	pthread_mutex_lock(&mutex);
	while(i <= 1)
	{
		write(1, (char *)buf, strlen(buf));
		i++;
		//usleep(1000);
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void *print2(void *buf)
{
	int i = 0;

	while(i < 5)
	{
		write(1, (char *)buf, strlen(buf));
		i++;
		//usleep(100000);
	}
	return NULL;
}

int main()
{
	char *str1 = "1_1_1_1_1_\n";
	char *str2 = "_2_2_2_2_2\n";
	char *str3 = "3_3_3_3_3_\n";

	pthread_t	t1, t2, t3;
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&t1, NULL, print, (void *)str1);
	pthread_create(&t2, NULL, print, (void *)str2);
	pthread_create(&t3, NULL, print, (void *)str3);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	//print((void *)str1);
	//print((void *)str2);
	//usleep(100000);
	pthread_mutex_destroy(&mutex);
	write(1, "Exit\n",5);
	return (0);
}