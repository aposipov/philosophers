

#include "../inc/philo.h"

void	get_fork2(t_philo *test)
{
	printf(MAGENTA"get_fork_2 %d\n"NC, test->n);
}

void	get_fork(t_philo *test)
{
	pthread_mutex_lock(&test->mutex);
	printf(MAGENTA"get_fork %d\n"NC, test->n);
	get_fork2(test);
	pthread_mutex_unlock(&test->mutex);
}

void	*print2(t_philo *test)
{
	int i = 0;
	int local;
	//test->n = (t_philo *)malloc(sizeof(t_philo) * test->data.num_phil);
	local = test->n;
	printf(BLUE"phil-%d, ready\n"NC, test->n);
	local = local + 1;
	test->n = local;
	get_fork(test);
	//return NULL;
}

void	*print(t_philo *test)
{
	printf(GREEN"num of philo %d\n"NC, test->data.num_phil);
	printf(RED"time to die %d\n"NC, test->data.time_die);
	printf("time to eat %d\n", test->data.time_eat);
	printf("time to sleep %d\n", test->data.time_sleep);
	printf(YELLOW"time to must eat %d\n"NC, test->data.num_must_eat);
	printf("ok\n");

	return(0);
}

void create_th(t_philo *test)
{
	int i = 0;
	//pthread_mutex_t mutex;

	test->th = (t_philo *)malloc(sizeof(t_philo) * test->data.num_phil);
	//test->n = (t_philo *)malloc(sizeof(t_philo) * test->data.num_phil);
	pthread_mutex_init(&test->mutex, NULL);
	while (i < test->data.num_phil)
	{

		//printf("n = %d\n", test->n[i]);
		pthread_create(&test->th[i], NULL, print2, test);
		i++;
	}
	//usleep(1000000);
//	i = 0;
//	while (i < test->data.num_phil)
//	{
//		pthread_join(test->th[i], NULL);
//		i++;
//	}
}

int main(int argc, char **argv)
{
	t_philo	*test;

	test = (t_philo *) malloc(sizeof(t_philo));
	if (argc < 5 || argc >6)
	{
		printf("check arguments!");
		return (0);
	}
	test->data.num_phil = ft_atoi(argv[1]);
	test->data.time_die = (ft_atoi(argv[2])) * ms;
	test->data.time_eat = ft_atoi(argv[3]) * ms;
	test->data.time_sleep = ft_atoi(argv[4]);
	//if (argc == 5) // free eat
	if (argc == 6)
		test->data.num_must_eat = ft_atoi(argv[5]);
	print(test);
	create_th(test);
	usleep(500000);

	return (0);
}