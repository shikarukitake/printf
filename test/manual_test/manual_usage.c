//
// Created by dan on 1/11/20.
//

#include "ft_printf.h"
#include <float.h>
#include <string.h>
#include <wchar.h>
#include <unistd.h>

#define PREFIX1  128
#define PREFIX2  192
#define PREFIX3  224
#define PREFIX4  240

int main()
{
	unsigned char buf[2];

	wint_t w;

	w = L'ø';

	buf[0] = (w >> 6u) + PREFIX2;
	buf[1] = (w & 63u) + PREFIX1;
	//write(1, buf, 2);
	ft_printf("%Lc", w);
}

//
//#include <locale.h>
//#include <wchar.h>
//
//int main()
//{
//	wchar_t suits[4] = {
//			0x2660, 0x2665, 0x2663, 0x2666
//	};
//	int x;
//
//	setlocale(LC_CTYPE,"UTF-8");
//
//	printf("Enter suit: ( ");
//	for(x=0;x<4;x++)
//	{
//		wprintf(L"%lc ",suits[x]);
//	}
//	printf("): ");
//
//	return(0);
//}