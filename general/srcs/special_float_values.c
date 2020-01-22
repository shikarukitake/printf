//
// Created by Aletha Yellin on 21/01/2020.
//

#include "special_float_values.h"

int is_inf(t_ldc ldc)
{
	return (ldc.parts.e == 32767u &&
			ldc.parts.m == 9223372036854775808ul &&
			ldc.parts.s == 0u);
}

int is_ninf(t_ldc ldc)
{
	return (ldc.parts.e == 32767u &&
			ldc.parts.m == 9223372036854775808ul &&
			ldc.parts.s == 1u);
}

int is_nan(t_ldc ldc)
{
	return (ldc.parts.e == 32767u &&
			(ldc.parts.m == 13835058057429647360ul || ldc.parts.m == 8u));
}

int is_reserved_value(t_ldc ldc, long double ld, char *fbuf)
{
	if (ld == 0 && ldc.parts.s == 1u)
	{
		ft_strcpy(fbuf, "-0.0");
		return (1);
	} else if (ld == 0 || ld == LDBL_MIN)
	{
		ft_strcpy(fbuf, "0.0");
		return (1);
	} else if (ld == - LDBL_MIN)
	{
		ft_strcpy(fbuf, "-0.0");
		return (1);
	} else if (is_inf(ldc))
	{
		ft_strcpy(fbuf, "inf");
		return (1);
	} else if (is_ninf(ldc))
	{
		ft_strcpy(fbuf, "-inf");
		return (1);
	} else if (is_nan(ldc))
	{
		ft_strcpy(fbuf, "nan");
		return (1);
	}
	return (0);
}