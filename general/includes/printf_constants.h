//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_PRINTF_CONSTANTS_H
#define PRINTF_PRINTF_CONSTANTS_H

#define MAX_SIZE_SPECS 8

#define MAX_LL_BUFF_SIZE (sizeof(long long) * 8 + 1)

#define MAX_P_BUFF_SIZE (sizeof (void*) * 8  + 1)

#define MAX_HEX_BUF_SIZE (sizeof(unsigned long long) * 8 +1)

#define MAX_FLOAT_BUFF_SIZE 4096

#define FT_PRINTF_SPEC_TYPES "ncpsdiouxXaAeEfFgG"

#define FT_PRINTF_TYPES "ncpsdiouxXaAeEfFgG%"

#define MAX_CHAR_BUF_SIZE 5

#define FT_CHAR_NULL "^@"

#define FT_PRINTF_FLAGS "-+ #0"

#define FT_PRINTF_INT_TYPES "diouxX"

const char *g_size_specs[MAX_SIZE_SPECS];

//TODO: stdint constants are allowed for printf?

typedef unsigned long long	t_ull;
typedef unsigned long		t_ul;
typedef unsigned char		t_uc;
typedef unsigned int		t_ui;
typedef unsigned short		t_us;

#define HEX_SMALL_PREFIX  "0x"

#define HEX_BIG_PREFIX "0X"

#define BIN_PREFIX	"0b"

#define OCT_PREFIX "0"

#endif //PRINTF_PRINTF_CONSTANTS_H
