#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int g_var = 1;
char buf[] = "a write to stdout\n";

int main()
{
	int l_var;
	pid_t pid;

	l_var = 10;
	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
	{
		printf("write error\n");
		exit(0);
	}
	printf("fork start!\n");
	if ((pid = fork()) < 0)
	{
		printf("fork error\n");
		exit(0);
	}
	else if (pid == 0)
	{
		g_var++;
		l_var++;
	}
	else
		sleep(3);

	printf("pid = %ld, g_var = %d, l_var = %d\n", (long)getpid(), g_var, l_var);
	exit(0);
}
