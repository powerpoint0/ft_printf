#include "ft_printf.h"
#include <stdio.h>

static char	ft_next_ch(long long int num, int base)
{
	const char	*base_16;

//	base_16 = "0123456789ABCDEF";
	base_16 = "0123456789abcdef";
	return (base_16[num]);
}
void		ft_itoa16(long long int num, char *rez, int base)
{
	int					size;
	long long int		tmp;

	size = 1;
	tmp = num;
	while(tmp /= base)
		size ++;
	while(size--)
	{
		rez[size] = ft_next_ch(num % base, base);
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
	ft_itoa16(num, str+6, 16);
	len = ft_strlen(str);
	size = (len > prn->width) ? len : prn->width;
	ft_print_type(size,len, prn, str);
	return (size);
}