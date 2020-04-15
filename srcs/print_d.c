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
void ft_ready_number(char *rstr,int len, char *str, t_prn *prn)
{
	int i;

	i = 0;
	if (prn->fl_plus)
		(prn->sign >=0) ?(rstr[i++] = '+') :(rstr[i++] = '-');
	else
		{
			if(prn->sign < 0)
				rstr[i++] = '-';
			if ((prn->sign >= 0)&& prn->fl_space)
				(rstr[i++] = ' ');
		}
	if((prn->precision ==-1) && (prn->width > len) && prn->fl_zero)
		prn->precision = prn->width -i;
	else
		prn->precision = (prn->precision <= len)? len : prn->precision;
	while (len++ != prn->precision)
		rstr[i++] = '0';
	ft_strcpy(&rstr[i], str);
}
int print_d(t_prn *prn)
{
	int len;
	int size;
	char str[27];
	char rstr[27];

	ft_bzero(str, 27);
	ft_bzero(rstr, 27);
	ft_itoa16((va_arg(prn->ap, int)) , str, 10, prn);
	len = ft_strlen(str);
	ft_ready_number(rstr,len, str, prn);
	len = ft_strlen(rstr);
	size = (prn->width > len) ? prn->width : len;
	ft_print_type(size, len, prn, rstr);
	return (0);
}