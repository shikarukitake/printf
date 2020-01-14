//
// Created by dan on 1/14/20.
//

#include "ft_printf.h"
#include "minunit.h"


static char *basic_test()
{
	mu_assert_printf("just oct", ft_printf, "%o", 123);
	return (0);
}

static char *more_complex_test()
{
	mu_assert_printf("width oct", ft_printf, "%10o", 123);
	return (0);
}

static char *wp_test()
{
	mu_assert_printf("width and precision oct", ft_printf, "%10.5o", 123);
	mu_assert_printf("width and precision oct", ft_printf, "%5.10o", 123);
	mu_assert_printf("width and precision oct and flag", ft_printf, "%#10.5o", 123);
	mu_assert_printf("width and precision oct and minus flag", ft_printf, "%-5.10o", 123);
	return (0);
}

static char *flag_test()
{
	mu_assert_printf("flag plus and oct", ft_printf, "%+o", 123);
	return (0);
}

int main()
{
	test_all("SIMPLE O TESTS", 4, wp_test, basic_test, more_complex_test, flag_test);
}