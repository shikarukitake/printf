//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_PRINTF_CONSTATNS_H
#define PRINTF_PRINTF_CONSTATNS_H

#define MAX_SIZE_SPECS 8

#define MAX_LL_BUFF_SIZE (sizeof(long long) * 8 + 1)

#define MAX_P_BUFF_SIZE (sizeof (void*) * 8  + 1)

static const char *g_type_specs = "ncpsdiouxXaAeEfFgG";

static const char *g_flags = "-+ #0";

static const char *g_int_type_specs = "diouxX";

static const char *g_size_specs[MAX_SIZE_SPECS] = {"l", "ll", "h", "hh", "j", "z", "t", "L"};

//TODO: printf stdint constants are allowed?

typedef unsigned long long	t_ull;
typedef unsigned long		t_ul;
typedef unsigned char		t_uc;
typedef unsigned int		t_ui;
typedef unsigned short		t_us;

#define LL_KEY 1

#define HH_KEY 3

#endif //PRINTF_PRINTF_CONSTATNS_H
