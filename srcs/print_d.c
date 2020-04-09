#include "ft_printf.h"

char *ft_putnbr_in_str(int n, char *str)
{
	int i;
	int k;

	k =0;
	i = -1000000000;
	if(n == 0)
	{
		str[k] = '0';
		return(str);
	}
	(n >= 0) ? (n *= -1) :(str[k++] = '-');
	while (n / i == 0)
		i = i /10;
	while(i)
	{
		str[k++] = (n/i + '0');
		n = n % i;
		i /= 10;
	}
	return(str);
}

int print_d(t_prn *prn)
{
	int len;
	int size;
	char str[12];

	ft_bzero(str, 12);
	ft_putnbr_in_str(va_arg(prn->ap, int) , str);
	len = ft_strlen(str);
	if(prn->precision > len || prn->precision ==-1)
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
	ft_print_type(size, len, prn, str);
	//printf("\n%d", len);
	return (0);
}