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