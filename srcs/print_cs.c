#include "ft_printf.h"
#include <stdio.h>

void ft_print_type_csp(int size,int len, t_prn  *prn, char *str)
{
	int		i;

	i = 0;
	while(i < size)
	 {
		if (prn->fl_minus == 0)
			(i < (size - len)) ? (write(1, " ", 1)) : (write(1, &str[i - (size - len)], 1));
		if (prn->fl_minus == 1)
			(i < len) ? write(1, &str[i], 1) : write(1, " ", 1);
		i++;
	}
}

int print_c(t_prn *prn)
{
	char	str[1];
	int		size;
	int		len;

	size = (prn->width) ? (prn->width) : 1;
	len =1;
	str[0] = (char)va_arg(prn->ap, int);
	ft_print_type_csp(size,len, prn, str);
	return (size);
}

int print_s(t_prn *prn)
{
	int		len;
	char	*str;
	int		size;

	str = va_arg(prn->ap, char*);
	len = ft_strlen(str);
	if(prn->precision > len || prn->precision == -1)
		prn->precision = len;
	len = prn->precision;
	if (prn->width)
		size = prn->width;
	else if (prn->precision >= 0 )
		size = prn->precision;
	else
		size = ft_strlen(str);
	ft_print_type_csp(size, len, prn, str);
	return (size);
}