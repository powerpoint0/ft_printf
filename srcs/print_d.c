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
void ft_ready_number(char *rstr,char *str, t_prn *prn)
{
	ft_bzero(rstr, 27);
	//znaki + -
	//probel?
	//00precision
	//copy number
}
int print_d(t_prn *prn)
{
	int len;
	int size;
	char str[27];
	char readystr[27];

	ft_bzero(str, 27);
	ft_itoa16((va_arg(prn->ap, int)) , str, 10, prn);
	len = ft_strlen(str);
	//ft_ready_number(readystr, *str, *prn);
	if (prn->width > len)
	{
		size = prn->width;
		len = (prn->precision>len-1)? (prn->precision+1): len;
	}
	else if (prn->precision > len )
	{
		size = prn->precision;
		len = prn->precision;
	}
	else size = len;
	ft_print_type(size, len, prn, str);
	//printf("\n%d", len);
	return (0);
}