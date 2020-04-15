#include "includes/ft_printf.h"
#include <stdio.h>

/*int		print_x(t_prn *prn)
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
}*/

int		print_x(t_prn *prn)
{
	int len;
	int size;
	char str[27];
	unsigned int		num;

	ft_bzero(str, 27);
	num = (unsigned int)va_arg(prn->ap,unsigned int );
	ft_itoa16(/*(va_arg(prn->ap, unsigned int))*/ num , str, 16, prn);
	len = ft_count_len(ft_strlen(str), str,prn);
	size = (prn->width > len) ? prn->width : len;
	ft_print_number(len, size, str, prn);
	return (0);
}