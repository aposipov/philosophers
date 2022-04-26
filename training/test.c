//
// Created by user on 24.04.22.
//

#include <stdio.h>
#include "../training/test.h"

void	get_init(t_test *example)
{
	example->count = 101;
	printf("count 2 = %d\n", example->data.count2);
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
	printf("get init 3 %d\n", example.count);
	get_init4(&example);
	printf("get init 4 %d\n", example.count);
	printf("get init 4 %d\n", example.data.count2);


	return(0);
}