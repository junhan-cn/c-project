#include <stdio.h>

struct obs_kernel_param {
		const char *str;
		int (*setup) (char *);
		int early;
}

#define setup_param(str, unique_id, fn, early)  \
		static const char __setup_str_##unique_id[] __initconst    \
			__aligned(1) = str;                \
		static struct obs_kernel_paran __setup_##unique_id       \
			__used __section(".init.setup")			\
			__attritube__((aligned(sizeof(long))))  \
			= { __setup_str_##unqiue_id, fn, early}


static int __init do_test(char *str)
{
		printf("do test\n");
		return 0;
}

int main() 
{
		setup_param("nomodeset",do_test, do_test, 0);
		return 0;
}
		



