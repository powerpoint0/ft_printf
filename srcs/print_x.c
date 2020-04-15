#include "includes/ft_printf.h"
#include <stdio.h>

int		print_x(t_prn *prn)
{
	long long int num;
	char str[27];
	int len;
	int size;
	int i;

	i = 0;
	ft_bzero(str, 27);
	num = va_arg(prn->ap, unsigned int);
	ft_itoa16(num, str, 16, prn);
	len = ft_strlen(str);
	if (prn->fl_sharp == 1)
		len +=2;
	if (prn->precision > len)
		len = prn->precision;
	if (prn->fl_minus > 0)
		size = len;
	else
		size = (len > prn->width) ? len : prn->width;
	i = 0;
	while (i++ < (size - len))
	{
		if (prn->fl_zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	if (prn->fl_sharp == 1)
	{
		ft_putstr("0x");
		len -=2;
	}
	i = 0;
	while (i++ < (prn->precision - ft_strlen(str)))
		ft_putchar('0');
	ft_putstr(str);
	return (size);
}