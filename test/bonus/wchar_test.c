//
// Created by Aletha Yellin on 23/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"

//static char *pft_test()
//{
//	mu_assert_printf("test 1", ft_printf, "%Lc", L'¢');
//	return (0);
//}
//
//static char *pft_test2()
//{
//	mu_assert_printf("test 1", ft_printf, "%C", L'Ã');
//	return (0);
//}
//
//static char *wiki_test()
//{
//	wchar_t wch;
//
//	wch = L'𐍈';
//	mu_assert_printf("test 1", ft_printf, "%Lc", wch);
//	return (0);
//}

static char *another_test()
{
	wchar_t suits[4] = {
			0x2660, 0x2665, 0x2663, 0x2666
	};

	mu_assert_printf("cards test", ft_printf, "%lc", suits[0]);
	mu_assert_printf("cards test", ft_printf, "%lc", suits[1]);
	mu_assert_printf("cards test", ft_printf, "%lc", suits[2]);
	mu_assert_printf("cards test", ft_printf, "%lc", suits[3]);
	return (0);
}

int main()
{
	test_all("WIDE CHAR TEST", 1, another_test);
	return (0);
}
