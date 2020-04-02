#include "ft_printf.h"
#include <stdio.h>

void ft_print(int size,int len,int minus, char *str)
{
	int		i;

	i = 0;
	while(i < size) {
		if (minus == 0) {
			if (i < (size - len))
				write(1, " ", 1);
			if (i >= (size - len))
				write(1, &str[i - (size - len)], 1);
		}
		if (minus == 1) {
			if (i < len)
				write(1, &str[i], 1);
			if (i >= len)
				write(1, " ", 1);
		}
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
	str[0] = va_arg(prn->ap, char);
	ft_print(size,len, prn->fl_minus, str);
	printf("|size = %d|", size);
	return (size);
}

int print_s(t_prn *prn)
{
	int		len;
	char	*str;
	int		size;

	str = va_arg(prn->ap, char*);
	len = ft_strlen(str);
	if(prn->precision > len)
		prn->precision = len;
	if (prn->width)
	{
		size = prn->width;
		len = prn->precision;
	}
	else if (prn->precision >= 0 )
	{
		size = prn->precision;
		len = prn->precision;
	}
	else size = len;
	ft_print(size,len, prn->fl_minus, str);
	printf("|size = %d|", size);
	return (size);
}