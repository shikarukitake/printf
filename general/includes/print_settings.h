//
// Created by Aletha Yellin on 25/12/2019.
//

#ifndef PRINTF_PRINT_SETTINGS_H
#define PRINTF_PRINT_SETTINGS_H

typedef struct s_print_settings
{
    int color_id;
    int fd;
}               t_print_settings;

typedef struct s_str_pair
{
    const char *key;
    const char *value;
}               t_str_pair;

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define MAX_COLORS 6

#define FD_FLAG  'w'



#endif //PRINTF_PRINT_SETTINGS_H
