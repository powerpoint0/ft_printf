#include "ft_printf.h"
#include <stdio.h>

void		ft_itoa16(long int num, char *rez, int base, char *basee)
{
	int			size;
	long int	tmp;
	long int	n;

	size = 1;
	tmp = num;
	if(num == 0)
	{
		*rez = '0';
		return;
	}
	n = (num >= 0)? -num : num;
	while(tmp /= base)
		size ++;
	while(size--)
	{
		rez[size] = basee[(-1)*(n % base)];
		n /= base;
	}
}

int		print_p(t_prn *prn)
{
	unsigned int		num;
	char				str[27] = "0x7fff";
	int					len;
	int					size;

	ft_bzero(str+6, 27);
	num = (unsigned int)va_arg(prn->ap, void*);
	ft_itoa16(num, str+6, 16, "0123456789abcdef");
	len = ft_strlen(str);
	size = (len > prn->width) ? len : prn->width;
	ft_print_type_csp(size,len, prn, str);
	return (size);
}

int		print_ouxX(t_prn *prn)
{
	int len;
	int size;
	char str[27];
	long int num;

	ft_bzero(str, 27);
	num = (long)va_arg(prn->ap, unsigned int);
	if (prn->type == 'o')
		ft_itoa16( num, str, 8, "01234567");
	else if (prn->type == 'u')
		ft_itoa16( num, str, 10, "0123456789");
	else if (prn->type == 'x')
		ft_itoa16(num, str, 16, "0123456789abcdef");
	else if (prn->type == 'X')
		ft_itoa16(num, str, 16, "0123456789ABCDEF");
	len = ft_count_len(ft_strlen(str), str,prn);
	size = (prn->width > len) ? prn->width : len;
	ft_print_number(len, size, str, prn);
	return (0);
}
