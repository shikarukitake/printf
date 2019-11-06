//
// Created by Aletha Yellin on 06/11/2019.
//

#include "minunit.h"
#include "ft_stdio.h"


static char *general_test()
{
	return (assert_printf("basic format", ft_printf, "Hello, world", FT_NULL));
}

int main()
{
	test_all("General", 1, general_test);
}