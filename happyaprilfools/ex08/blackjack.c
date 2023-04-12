#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	isfaces(char ref)
{
	char	*faces = "TJQK";
	for (int i = 0; faces[i]; ++i)
		if (faces[i] == ref)
			return (i + 1);
	return (0);
}

int	handle_aces(int	num, int score)
{
	for (; num > 0; --num)
		score += ((score + 11) <= 21 && num == 1) ? 11 : 1;
	return (score);
}

int main(int ac, char **av)
{
	char	*check = av[1];
	int		score = 0, aces = 0;
	for (int i = 0; check[i]; ++i)
		(isdigit(check[i])) ? score += check[i] - '0' : (isfaces(check[i])) ? score += 10 : ++aces;
	score = handle_aces(aces, score);
	printf("Score = %d\n", score);
}