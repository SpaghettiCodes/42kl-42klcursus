#include <sys/time.h>
#include <stdio.h>
#include <limits.h>

// typedef struct s_timeval 
// {
// 	time_t      tv_sec;     /* seconds */
// 	suseconds_t tv_usec;    /* microseconds */
// } t_timeval;

typedef struct s_timezone {
	int tz_minuteswest;     /* minutes west of Greenwich */
	int tz_dsttime;         /* type of DST correction */
}	t_timezone;

long int	gettime()
{
	struct timeval time;
	t_timezone	dont_care;
	gettimeofday(&time, &dont_care);

	return ((time.tv_sec * 1000000) + time.tv_usec);
}

int main()
{
	long int	start = gettime();

	int i = 0;
	while (i < 1e5)
		i++;
	
	long int	end = gettime();
	printf("This program took: %ld Microseconds\n", end - start);
	printf("Start = %ld, End = %ld\n", start, end);
}