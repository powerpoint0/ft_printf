#include "ft_printf.h"
#include <stdio.h>

int		print_x(t_prn *prn)
{
	int len;
	int size;
	char str[27];

	ft_bzero(str, 27);
	ft_itoa16((long)va_arg(prn->ap, unsigned int) , str, 16, prn);
	len = ft_count_len(ft_strlen(str), str,prn);
	size = (prn->width > len) ? prn->width : len;
	ft_print_number(len, size, str, prn);
	return (0);
}

int		print_o(t_prn *prn)
{
	int len;
	int size;
	char str[27];

	ft_bzero(str, 27);
	ft_itoa16((long)va_arg(prn->ap, unsigned int) , str, 8, prn);
	len = ft_count_len(ft_strlen(str), str,prn);
	size = (prn->width > len) ? prn->width : len;
	ft_print_number(len, size, str, prn);
	return (0);
}