#include "ft_printf.h"
/*long long int	ft_mod_llhh(long long int nbr, t_prn *prn)
{
	long long int	nbr;

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
}*/

int ft_count_len(int len, char *str,t_prn *prn)
{
	int sign;

	if (prn->sign == -1 || prn->fl_space || prn->fl_plus)
		sign = 1;
	else sign = 0;
	if (prn->fl_sharp)
	{
		sign += ((len <= prn->precision) && (prn->type == 'o')) ? 1 : 0;
		sign += ((prn->type == 'x' || (prn->type == 'X'))) ? 2 : 0;
	}
	if((prn->precision ==-1) && (prn->width > len) && prn->fl_zero)
		prn->precision = prn->width -sign;
	else
		prn->precision = (prn->precision <= len)? len : prn->precision;
	len = sign + prn->precision;
	return(len);
}

void ft_print_flags_numberType(int len, char *str, t_prn *prn)
{
	if (prn->fl_sharp)
	{
		if (((len == prn->precision) && (prn->type == 'o')) || (prn->type == 'x')|| (prn->type == 'X'))
			write(1, "0", 1);
		if (prn->type == 'x' || (prn->type == 'X'))
			write(1, &prn->type, 1);
	}
	if (prn->fl_plus)
		(prn->sign >=0) ?(write(1, "+",1)) :(write(1, "-",1));
	else
		{
			if(prn->sign < 0)
				write(1, "-",1);
			if ((prn->sign >= 0)&& prn->fl_space)
				write(1, " ",1);
		}
	while (len++ != prn->precision)
		write(1, "0", 1);
	ft_putstr(str);
}

void ft_print_number(int len, int size,char *str, t_prn *prn)
{
	if (prn->fl_minus)
	{
		ft_print_flags_numberType(ft_strlen(str), str, prn);
		while (len++ < size)
			write(1, " ", 1);
	}
	else
	{
		while (size - len++)
			write(1, " ", 1);
		ft_print_flags_numberType(ft_strlen(str), str, prn);
	}
}

int print_d(t_prn *prn)
{
	int len;
	int size;
	char str[27];
	int num;

	ft_bzero(str, 27);
	num = va_arg(prn->ap, int);
	ft_itoa16( num, str, 10, "0123456789");
	prn->sign = (num >= 0)? 1: (-1);
	len = ft_count_len(ft_strlen(str), str,prn);
	size = (prn->width > len) ? prn->width : len;
	ft_print_number(len, size, str, prn);
	return (0);
}