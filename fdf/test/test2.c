#include <stdio.h>

int	putcolor(unsigned char trans, unsigned char r, unsigned char g, unsigned char b)
{
	int	ret;

	ret = trans << 24 | r << 16 | g << 8 | b;
	return (ret);
}

int main()
{
	unsigned char trans, r, g , b;
	
	trans = 255;
	r = 127;
	g = 2;
	b = 1;
	printf("%u\n", putcolor(trans, r , g , b)); 
}