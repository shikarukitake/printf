//
// Created by Aletha Yellin on 12/11/2019.
//
#include "minunit.h"
#include "ft_printf.h"

static char *simple_test()
{
	mu_assert_printf("two percents", ft_printf, "%%", MU_NULL);
	return (0);
}

static char *digit_test()
{
	mu_assert_printf("percent and extra digit", ft_printf, "%-5%", MU_NULL);
	return (0);
}

static char *digit_test2()
{
	mu_assert_printf("two percent and  d", ft_printf, "%-5% %+5d", 123);
	return (0);
}

//// EXTRA TEST
//static char *one_percent()
//{
//	mu_assert_printf("one percent and digits", ft_printf, "1%2", MU_NULL);
//	return (0);
//}

static char *only_percent()
{
	mu_assert_printf("alone percent", ft_printf, "%", MU_NULL);
	return (0);
}

static char *one_percent2()
{
	mu_assert_printf("percent and precision", ft_printf, "%.0%", MU_NULL);
	return (0);
}

static char *too_much_wh()
{
	mu_assert_printf("percent and wh", ft_printf, "%      %", MU_NULL);
	return (0);
}

static char *zero_flag_test()
{
    mu_assert_printf("percent and zero flag", ft_printf, "%05%", MU_NULL);
    return (0);
}

static char *percent_return()
{
	mu_assert_printf_return("basic", ft_printf, "%%", MU_NULL);
	return (0);
}

int main(void)
{
	test_all("JUST PERCENT", 8,
			 simple_test,
			 digit_test,
			 digit_test2,
			 one_percent2,
			 only_percent,
			 too_much_wh,
			 zero_flag_test,
			 percent_return);
	return (0);
}