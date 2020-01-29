//
// Created by Aletha Yellin on 25/12/2019.
//

#include "ft_printf.h"
#include "minunit.h"

#define PAGES 959

static char *example1()
{
    mu_assert_printf("test1", ft_printf, "*%d*\n", PAGES);
    mu_assert_printf("test1", ft_printf, "*%2d*\n", PAGES);
    mu_assert_printf("test1", ft_printf, "*%10d*\n", PAGES);
    mu_assert_printf("test1", ft_printf, "*%-10d*\n", PAGES);
    return (0);
}

#define BLURB "Authentic imitation!"

static char *example2()
{
    const double RENT = 3852.99;
    mu_assert_printf("1", ft_printf, "*%8f*", RENT);
    mu_assert_printf("2", ft_printf, "*%e*", RENT);
    mu_assert_printf("3", ft_printf, "*%4.2f*", RENT);
    mu_assert_printf("4", ft_printf, "*%3.1f*", RENT);
    mu_assert_printf("5", ft_printf, "*%10.3f*", RENT);
    mu_assert_printf("6", ft_printf, "*%10.3E*", RENT);
    mu_assert_printf("7", ft_printf, "*%+4.2f*", RENT);

    mu_assert_printf("8", ft_printf, "%x %X %#x", 31, 31, 31);
    mu_assert_printf("9", ft_printf, "**%d**% d% d **", 42, 42, -42);
    mu_assert_printf("10", ft_printf, "**%5d**%5.3d**%05d**%05.3d**", 6, 6, 6, 6);

    mu_assert_printf("11", ft_printf,"[%2s]", BLURB);
    mu_assert_printf("12", ft_printf,"[%24s]", BLURB);
    mu_assert_printf("13", ft_printf,"[%24.5s]", BLURB);
    mu_assert_printf("14", ft_printf,"[%-24.5s]", BLURB);

    return (0);
}

int main()
{
    test_all("WIKI EXAMPLES", 2, example1, example2);
}