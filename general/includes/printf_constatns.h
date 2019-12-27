//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_PRINTF_CONSTATNS_H
#define PRINTF_PRINTF_CONSTATNS_H

#define MAX_SIZE_SPECS 8

#define MAX_LL_BUFF_SIZE (sizeof(long long) * 8 + 1)

#define MAX_P_BUFF_SIZE (sizeof (void*) * 8  + 1)

#define MAX_LD_BUF_SIZE (sizeof(long double) * 8 + 1)

#define MAX_FLOAT_BUFF_SIZE 4096

static const char *g_type_specs = "ncpsdiouxXaAeEfFgG";

static const char *g_flags = "-+ #0";

static const char *g_int_type_specs = "diouxX";

static const char *g_size_specs[MAX_SIZE_SPECS] = {"l", "ll", "h", "hh", "j", "z", "t", "L"};

//TODO: stdint constants are allowed for printf?

typedef unsigned long long	t_ull;
typedef unsigned long		t_ul;
typedef unsigned char		t_uc;
typedef unsigned int		t_ui;
typedef unsigned short		t_us;

#define HEX_SMALL_PREFIX  "0x"

#define HEX_UPPER_PREFIX "0X"

#define BIN_PREFIX	"0b"


#endif //PRINTF_PRINTF_CONSTATNS_H
