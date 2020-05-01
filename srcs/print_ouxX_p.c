#include "ft_printf.h"

uintmax_t	ft_get_unsigned_mod_llhh(t_prn *prn)
{
	uintmax_t nbr;

 	nbr = va_arg(prn->ap, uintmax_t);
	if (prn->mod_hh)
		nbr = (unsigned char)nbr;
	else if (prn->mod_h)
		nbr = (unsigned short int)nbr;
	else if (prn->mod_l)
		nbr = (unsigned long int)nbr;
	else if (prn->mod_ll)
		nbr = (unsigned long long int)nbr;
	//else if (arg->length == j)
		//nbr = (uintmax_t)nbr;
	//else if (arg->length == z)
		//nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}


void		ft_itoa16(intmax_t num, char *rez, int base, char *basee)
{
	int			size;
	intmax_t	tmp;
	intmax_t	n;

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
	uintmax_t num;

	ft_bzero(str, 27);
	prn->sign = 0;
	num = ft_get_unsigned_mod_llhh(prn);
	if (prn->type == 'o')
		ft_itoa16( num, str, 8, "01234567");
	else if (prn->type == 'u')
		ft_itoa16( num, str, 10, "0123456789");
	else if (prn->type == 'x')
		ft_itoa16(num, str, 16, "0123456789abcdef");
	else if (prn->type == 'X')
		ft_itoa16(num, str, 16, "0123456789ABCDEF");
	len = ft_count_len(ft_strlen(str), prn);
	size = (prn->width > len) ? prn->width : len;
	ft_print_number(len, size, str, prn);
	return (size);
}
