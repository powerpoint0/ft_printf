#include "ft_printf.h"
#include <stdio.h>

int		ft_isnan(long double nbr)
{
	union test_nan_union	tnan;

	tnan.d = (double) nbr;
	if (tnan.l == 0x7FF8000000000000 || tnan.l == 0xFFF8000000000000)
		return (1);
	return (0);
}

int		ft_isinf(long double nbr)
{
	union test_nan_union tnan;

	tnan.d = (double) nbr;
	if (tnan.l == 0x7FF0000000000000)
		return (1);
	if (tnan.l == 0xFFF0000000000000)
		return (-1);
	return (0);
}

long double	get_nbr(t_prn *prn)
{
	long double		nbr;

	if (prn->mod_L == 1)
		nbr = (long double)va_arg(prn->ap, long double);
	else
		nbr = (long double)va_arg(prn->ap, double);
	if (nbr < 0.0f)
		prn->neg = 1;
	return (nbr);
}

int		nan_inf(long double nbr, t_prn *prn, char *str)
{
	if (ft_isnan(nbr))
	{
		if (ft_islower(prn->type))
			ft_strcpy(str, "nan");
		else
			ft_strcpy(str, "NAN");
		prn->fl_zero = 0;
		prn->fl_plus = 0;
		prn->neg = 0;
		return (1);
	}
	if (ft_isinf(nbr) != 0)
	{
		str[0] = (ft_isinf(nbr) < 0) ? '-' : '+';
		if (ft_islower(prn->type))
			ft_strcpy(&str[1], "inf");
		else
			ft_strcpy(&str[1], "INF");
		prn->fl_zero = 0;
		prn->neg = 0;
		return (1);
	}
	return (0);
}

int		print_f(t_prn *prn)
{
	long double				nbr;
	char					str[59];
	unsigned long long int	num;
	int						degree;

	ft_bzero(str, 59);
	nbr = get_nbr(prn);
	if (!nan_inf(nbr, prn, str))
	{
		if (prn->type == 'e' || prn->type == 'E')
			degree  = get_degree(&nbr);
		ft_itoa_unsigned((int) nbr, str, 0);
		str[ft_strlen(str)] = '.';
		if (prn->precision == -1)
			prn->precision = 6;
		num = iabs((long long int) ((nbr - (long long int) (nbr)) * dt(prn->precision + 1)));
		num = ((num % 10) >= (10 / 2)) ? (num / 10 + 1) : (num / 10);
		ft_itoa_unsigned(num, str, prn->precision);
		if (prn->type == 'e' || prn->type == 'E')
			add_exp(str, degree, prn);
		if (prn->type == 'g' || prn->type == 'G')
			cut_str(str);
	}
	print_format(prn, str);
	return (prn->width);
}