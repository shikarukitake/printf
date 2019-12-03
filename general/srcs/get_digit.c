//
// Created by Aletha Yellin on 29/11/2019.
//

#include "ft_printf.h"

void	get_general_digit(va_list vargs, t_convert_args args, t_spec *spec, char *buffer)
{
	if (spec->size.id == -1)
		args.i_convert(va_arg(vargs, int), buffer, args.base, args.a);
	else if (spec->size.value[0] == 'l' && spec->size.value[1] == 'l')
		args.ll_convert(va_arg(vargs, long long), buffer, args.base, args.a);
	if (spec->size.value[0] == 'l')
		args.ll_convert(va_arg(vargs, long), buffer, args.base, args.a);
	else if (spec->size.value[0] == 'h' && spec->size.value[1] == 'h')
		args.i_convert((short)va_arg(vargs, int), buffer, args.base, args.a);
	else if (spec->size.value[0] == 'h')
		args.i_convert((char)va_arg(vargs, int), buffer, args.base, args.a);
}