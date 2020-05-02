#include "ft_printf.h"

void ft_print_type_csp(int size,int len, t_prn  *prn, char *str)
{
	int		i;

	i = 0;
	while(i < size)
	 {
		if (prn->fl_minus == 0)
			(i < (size - len)) ? (write(prn->fd, " ", 1)) : (write(prn->fd, &str[i - (size - len)], 1));
		if (prn->fl_minus == 1)
			(i < len) ? write(prn->fd, &str[i], 1) : write(prn->fd, " ", 1);
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
	prn->size_symb += size;
	return (prn->size_symb);
}

int print_s(t_prn *prn)
{
	int		len;
	char	*str;
	int		size;

	if(!(str = va_arg(prn->ap, char*)))
	{
		write(prn->fd, "(null)",6);
		prn->size_symb += 6;
		return (-1);
	}
	if(prn->precision > (int)(ft_strlen(str)) || prn->precision == -1)
		prn->precision = ft_strlen(str);
	len = prn->precision;
	size = ft_strlen(str);
	if (prn->width )
		size = (prn->width > prn->precision) ? prn->width : prn->precision;
	else if (prn->precision >= 0 )
		size = prn->precision;
	ft_print_type_csp(size, len, prn, str);
	prn->size_symb += size;
	return (prn->size_symb);
}