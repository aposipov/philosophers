//
// Created by user on 24.04.22.
//

#include <stdio.h>

typedef struct	s_test2{
	int count2;
}	t_test2;

typedef struct	s_test{
	int count;
	t_test2 data;
}	t_test;

void	get_init(t_test *example)
{
	example->count = 101;
	printf("test 2 = %d\n", example->data.count2);
	//return(example->count);
}

void	get_init2(t_test *example)
{
	example->count = 333;
	//return(example->count);
}

void	get_init3(t_test *example)
{
	//example->count = 888;
	printf("init3 = %d\n", example->count);
	//return(example->count);
}

int	main()
{
	t_test	example;

	example.data.count2 = 111;
	get_init(&example);
	printf("count = %d\n", example.count);
	get_init2(&example);
	printf("count2 = %d\n", example.count);
	get_init3(&example);

	return(0);
}