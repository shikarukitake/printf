//
// Created by dan on 20.12.19.
//
#include "stdio.h"
#include "string.h"
// bit returned at location
int bit_return(unsigned a, int loc)
{
	int buf = a & 1u<<loc;
	return (buf == 0 ? 0 : 1);
}

int main()
{
	//11000010111011010100000000000000
	// 1 sign bit | 8 exponent bit | 23 fraction bits
	float a = -118.625;
	unsigned b;

	memcpy(&b, &a, sizeof(b));
	int i = 31;
	while(i >= 0)
	{
		printf("%d",bit_return(b, i));
		i--;
	}
	return 0;
}