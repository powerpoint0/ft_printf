#include "ft_printf.h"
#include <stdio.h>

static char	ft_next_ch( int num, int base)
{
	const char	*base_16;
	const char	*base_10;
	const char	*base_8;
	char *basee;

	base_8 = "01234567";
	base_10 = "0123456789";
//	base_16 = "0123456789ABCDEF";
	base_16 = "0123456789abcdef";
	if(base == 16)
		basee = base_16;
	if(base == 10)
		basee = base_10;
	if(base == 8)
		basee = base_8;
	return (basee[num]);
}
void		ft_itoa16(int num, char *rez, int base, t_prn *prn)
{
	int		size;
	int		tmp;

	size = 1;
	tmp = num;
	if(num == 0)
	{
		*rez = '0';
		return;
	}
	prn->sign = (num >= 0)? 1: (-1);
	num *= (num >= 0)? (-1) : 1;
	while(tmp /= base)
		size ++;
	while(size--)
	{
		rez[size] = ft_next_ch((-1)*(num % base), base);
		num /= base;
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
	ft_itoa16(num, str+6, 16, prn);
	len = ft_strlen(str);
	size = (len > prn->width) ? len : prn->width;
	ft_print_type(size,len, prn, str);
	return (size);
}