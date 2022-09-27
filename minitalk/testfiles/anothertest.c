#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void test()
{
	printf("leave the code.\n");
	exit(0);
}

void test1()
{
	printf("uhhhh?\n");
	exit(0);
}

void test2()
{
	printf("you are trolling\n");
	exit(0);
}

int main()
{
	signal(SIGINT, test);
	signal(SIGFPE, test1);
	signal(SIGSEGV, test2);
	char *test;
	test[323] = 123;
	while(1)
	{
		printf("runnign\n");
		sleep(3);
	}
}
