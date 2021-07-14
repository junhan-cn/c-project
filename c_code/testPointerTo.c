#include <stdio.h>

int main()
{
	static int desc[10];

	int *p = desc;

	int i;
	for(i = 0; i < 10; i++)
	{
		printf("%5d",desc[i]);
	}
	
	printf("\n");

	for(i = 1; i <= 10; i++)
	{
		*p++ = i;
	}

	for(i = 0; i < 10; i++)
	{
		printf("%5d",desc[i]);
	}

	printf("\n");

	return 0;
}
