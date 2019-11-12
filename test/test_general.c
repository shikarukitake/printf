//
// Created by Aletha Yellin on 06/11/2019.
//

#include "minunit.h"
#include "ft_stdio.h"


static char *general_test()
{
	//mu_assert_printf("basic format test", ft_printf, "%s", "Hello, world!");
	mu_assert_printf("NULL argument", ft_printf, "%s = %s", "wat", "WTF?!");
	return (0);
}

int main()
{
	test_all("General", 1, general_test);
}