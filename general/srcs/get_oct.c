//
// Created by Aletha Yellin on 03/12/2019.
//

#include "get_oct.h"
#include "libft.h"
#include "convert.h"
#include "get_digit.h"

void	get_oct(va_list vargs, t_spec *spec, char *buffer, char letter)
{
	t_convert_args	args;

	args = (t_convert_args) {0 , ft_itoa_base, ft_lltoa_base, 8, letter};
	get_general_digit(vargs, args, spec, buffer);
}