//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_PRINTF_CONSTATNS_H
#define PRINTF_PRINTF_CONSTATNS_H

# define FT_PRINTF_STR 1
# define FT_PRINTF_DIGIT 2
# define FT_PRINTF_PERCENT 3
# define FT_PRINTF_EMPTY 0

#define MAX_SIZE_SPECS 8

static const char *g_type_specs = "cpsdiouxXaAeEfFgG";

static const char *g_flags = "-+ #0";

static const char *g_size_specs[MAX_SIZE_SPECS] = {"l", "hh", "h", "ll", "j", "z", "t", "L"};

#endif //PRINTF_PRINTF_CONSTATNS_H
