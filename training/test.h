//
// Created by user on 26.04.22.
//

#ifndef TEST_H
#define TEST_H

typedef struct	s_test2{
	int count2;
}	t_test2;

typedef struct	s_test{
	int count;
	t_test2 data;
}	t_test;

void get_init4(t_test *tmp);

#endif TEST_H
