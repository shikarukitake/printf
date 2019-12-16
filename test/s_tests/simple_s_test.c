//
// Created by Aletha Yellin on 12/11/2019.
//

#include "minunit.h"
#include "ft_printf.h"

static char *basic_str(void)
{
	mu_assert_printf("first test", ft_printf, "%s", "Hello");
    return (0);
}


int main()
{
	test_all("SIMPLE STR PRINTF TESTS", 1, basic_str);
	return (0);
}