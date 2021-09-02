//函数指针练习

#include <stdio.h>


struct test_function_point {
		void(*add)(int,int);
		void(*reduce)(int,int);
};


void test_add(int a, int b)
{
		printf("test_add\n");
}

void test_reduce(int a, int b)
{
		printf("test_reduce\n");
}


int main()
{
		struct test_function_point test_point = {
				.add = test_add,
				.reduce = test_reduce
		};


		test_point.add(3,4);
		test_point.reduce(4,5);

		return 0;

}
