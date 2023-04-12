#include <stdio.h>

int	str_len(char *test)
{
	int ret;
	for (ret = 0; test[ret]; ++ret) {}
	return (ret);
}

int	is_palin(char *test)
{
	int	strlen = str_len(test);
	int	end = strlen - 1;
	for (int i = 0; i != strlen && i != end; ++i, --end)
	{
		if (test[i] != test[end])
			return (0);
	}
	return (1);
}

int main()
{
	printf("%d\n", is_palin("eawdmoawodm,t"));
}