//
// Created by Aletha Yellin on 29/11/2019.
//

#include "ft_printf.h"

void	get_general_d(va_list vargs, t_conv args, t_spec *spec, char *buf) {
	if (spec->size.id == -1)
		ft_itoa_base(va_arg(vargs, int), buf, args.base, args.a);
	else if (spec->size.value[0] == 'l' && spec->size.value[1] == 'l')
		ft_lltoa_base(va_arg(vargs, long long), buf, args.base, args.a);
	else if (spec->size.value[0] == 'l')
		ft_lltoa_base(va_arg(vargs, long), buf, args.base, args.a);
	else if (spec->size.value[0] == 'h' && spec->size.value[1] == 'h')
		ft_itoa_base((short) va_arg(vargs, int), buf, args.base, args.a);
	else if (spec->size.value[0] == 'h')
		ft_itoa_base((char) va_arg(vargs, int), buf, args.base, args.a);
}

void	get_general_ud(va_list vargs, t_conv args, t_spec *spec, char *buf) {
	if (spec->size.id == -1)
		ft_uitoa_base(va_arg(vargs, t_ui), buf, args.base, args.a);
	else if (spec->size.value[0] == 'l' && spec->size.value[1] == 'l')
		ft_ulltoa_base(va_arg(vargs, t_ull), buf, args.base, args.a);
	else if (spec->size.value[0] == 'l')
		ft_ulltoa_base(va_arg(vargs, t_ul), buf, args.base, args.a);
	else if (spec->size.value[0] == 'h' && spec->size.value[1] == 'h')
		ft_uitoa_base((t_us) va_arg(vargs, int), buf, args.base, args.a);
	else if (spec->size.value[0] == 'h')
		ft_uitoa_base((t_uc) va_arg(vargs, int), buf, args.base, args.a);
}


void	get_general_ptr(va_list vargs, t_conv args, t_spec *spec, char *buf) {
        ft_ulltoa_base((size_t)va_arg(vargs, size_t *), buf, args.base, args.a);
}