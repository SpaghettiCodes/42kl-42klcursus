#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include "get_next_line.h"
#include <semaphore.h>

void	q_swap(int *a, int *b);
int		partition(int *a, int first, int last);
// sort the list (sorted list will be used as base for logic)
void	q_sort(int *a, int first, int last);

#endif