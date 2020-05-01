#include "../includes/ft_printf.h"
#include <stdio.h>

long double	get_nbr(t_prn *prn)
{
	long double		nbr;

	if (prn->mod_L == 1)
		nbr = va_arg(prn->ap, long double);
	else
		nbr = (long double)va_arg(prn->ap, double);
	if (nbr < 0.0f)
	{
		nbr = -nbr;
		prn->sign = 1;
	} else
		prn->sign = 0;
	return (nbr);
}

void		write_to_string(long double nbr, char *str, t_prn *prn, int degree)
{
	int	i;
	int size_d;

	i = 0;
	size_d = (degree > 0) ? (degree + 1) : 1;
	while (i < (prn->precision + size_d + 1) && i < 315)
	{
		str[i] = (unsigned int) nbr + '0';
		nbr -= (unsigned int) nbr;
		nbr *= 10;
		i++;
	}
}

void		move_under_one(char *str, int degree)
{
	int	size;

	degree = - degree;
	size = ft_strlen(str) ;
	while (size >= 0)
	{
		str[size + degree] = str[size];
		size--;
	}
	while (--degree >= 0)
		str[degree] = '0';
}

int		corect_str(char *str, t_prn *prn, int degree)
{
	int	count;
	int	size;

	if (prn->type != 'e' && prn->type != 'E' && degree < 0)
		move_under_one(str, degree);
	size = (prn->type == 'e' || prn->type == 'E' || degree <= 0) ?
			(1 + prn->precision) : (1 + degree + prn->precision);
	if (str[size] >= '5' && str[size] <= '9')
	{
		count = size - 1;
		if (str[count + 1] == '9')
		{
			while (count > 0)
			{
				if (str[count] == '9')
					str[count] = '0';
				else
				{
					str[count] = str[count] + 1;
					count = 0;
				}
				count--;
			}
			if (count == 0 && str[count] == '9')
			{
				str[count] = '1';
				degree++;
				str[size] = '0';
			}
		}
		else
			str[count] = str[count] + 1;
	}
	str[size + 1] = '\0';
	return (degree);
}

int		print_efg(t_prn *prn)
{
	long double				nbr;
	char					str[315];
	int				degree;

	ft_bzero(str, 315);
	nbr = get_nbr(prn);
	if (!nan_inf(nbr, prn, str))
	{
		degree = get_degree(&nbr);
		if (prn->precision == -1)
			prn->precision = 6;
		write_to_string(nbr, str, prn, degree);
		degree = corect_str(str, prn, degree);
		add_point(str, prn, degree);
	}
	print_format(prn, str);
	return (prn->width);
}
