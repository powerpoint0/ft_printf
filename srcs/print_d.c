#include "../includes/ft_printf.h"

intmax_t	ft_get_signed_mod_llhh(t_prn *prn)
{
	intmax_t nbr;

 	nbr = va_arg(prn->ap, intmax_t);
	if (prn->mod_hh)
		nbr = (char)nbr;
	else if (prn->mod_h)
		nbr = (short int)nbr;
	else if (prn->mod_l)
		nbr = (long int)nbr;
	else if (prn->mod_ll)
		nbr = (long long int)nbr;
	//else if (arg->length == j)
		//nbr = (intmax_t)nbr;
	//else if (arg->length == z)
		//nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

int ft_count_len(int len, t_prn *prn)
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
			write(prn->fd, "0", 1);
		if (prn->type == 'x' || (prn->type == 'X'))
			write(prn->fd, &prn->type, 1);
	}
	if (prn->fl_plus)
		(prn->sign >=0) ?(write(prn->fd, "+",1)) :(write(prn->fd, "-",1));
	else
		{
			if(prn->sign < 0)
				write(prn->fd, "-",1);
			if ((prn->sign >= 0)&& prn->fl_space)
				write(prn->fd, " ",1);
		}
	while (len++ != prn->precision)
		write(prn->fd, "0", 1);
	ft_putstr_fd(str, prn->fd);
}

void ft_print_number(int len, int size,char *str, t_prn *prn)
{
	if (prn->fl_minus)
	{
		ft_print_flags_numberType(ft_strlen(str), str, prn);
		while (len++ < size)
			write(prn->fd, " ", 1);
	}
	else
	{
		while (size - len++)
			write(prn->fd, " ", 1);
		ft_print_flags_numberType(ft_strlen(str), str, prn);
	}
}

int print_di(t_prn *prn)
{
	int len;
	int size;
	char str[27];
	intmax_t num;

	ft_bzero(str, 27);
	num = ft_get_signed_mod_llhh(prn);
	ft_itoa16( num, str, 10, "0123456789");
	prn->sign = (num >= 0)? 1: (-1);
	len = ft_count_len(ft_strlen(str), prn);
	size = (prn->width > len) ? prn->width : len;
	ft_print_number(len, size, str, prn);
	return (0);
}