#include "ft_printf.h"
#include <stdio.h>

int		print_xX(t_prn *prn)
{
	int len;
	int size;
	char str[27];
	long int num;

	ft_bzero(str, 27);
	num = (long)va_arg(prn->ap, unsigned int);
	if (prn->type == 'x')
		ft_itoa16(num, str, 16, "0123456789abcdef");
	else if (prn->type == 'X')
		ft_itoa16(num, str, 16, "0123456789ABCDEF");
	len = ft_count_len(ft_strlen(str), str,prn);
	size = (prn->width > len) ? prn->width : len;
	ft_print_number(len, size, str, prn);
	return (0);
}

int		print_ou(t_prn *prn)
{
	int len;
	int size;
	char str[27];
	long int num;

	ft_bzero(str, 27);

	num =(long)va_arg(prn->ap, unsigned int);
	if (prn->type == 'o')
		ft_itoa16( num, str, 8, "01234567");
	else if (prn->type == 'u')
		ft_itoa16( num, str, 10, "0123456789");
	len = ft_count_len(ft_strlen(str), str,prn);
	size = (prn->width > len) ? prn->width : len;
	ft_print_number(len, size, str, prn);
	return (0);
}