//构建孤儿进程

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
		pid_t pid;
		pid = fork();


		if(pid == -1)
				perror("fork error\n");

		if(pid == 0) {
				sleep(1);
				printf("this is child process child pid = %d,parent pid=%d\n",getpid(),getppid());
		}

		if (pid > 0) {
				printf("this is parent pid = %d  pid = %d\n", getpid(),pid);
		}
		return 0;
}

