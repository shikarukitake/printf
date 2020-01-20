//
// Created by Aletha Yellin on 06/11/2019.
//

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

int main()
{
//    printf("%x and text", 0);
    char buf[10000];
    bzero(buf, 10000);

    sprintf(buf, "%Lf\n", LDBL_MAX);\

    printf("len = %lu\n", strlen(buf));
	return (0);
}