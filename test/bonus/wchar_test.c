//
// Created by Aletha Yellin on 23/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"

static char *pft_test()
{
	mu_assert_printf("test 1", ft_printf, "%C", L'ø');
	return (0);
}

int main()
{
	test_all("WIDE CHAR TEST", 1, pft_test);
	return (0);
}
