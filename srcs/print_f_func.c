#include "ft_printf.h"
#include <stdio.h>

int		get_degree(long double *nbr, t_prn *prn)
{
	int			degree;

	degree = 0;
	if ((*nbr) < 1.0e-15f)
		return (0);
	if ((*nbr) < 1.0f)
	{
		while ((*nbr) < 1.0f)
		{
			*nbr *= 10.0f;
			degree--;
		}
	}
	else
			while ((*nbr) >= 10.0f)
			{
				degree++;
				*nbr *= 0.1;
			}
	return (degree);
}

void	add_exp(char *str, int degree, t_prn *prn)
{
	int	count;
	int	tmp;
	int	size;

	count = ft_strlen(str);
	str[count++] = (ft_islower(prn->type) == 1) ? 'e' : 'E';
	str[count++] = (degree < 0) ? '-' : '+';
	degree = (degree < 0) ? -degree : degree;
	if (degree < 10)
	{
		str[count++] = '0';
		str[count] = degree + '0';
	}
	else
	{
		tmp = degree;
		size = 0;
		while(tmp /= 10)
			size++;
		str[count + size + 1] = '\0';
		while (size)
		{
			str[count + size--] = (degree % 10) + '0';
			degree /= 10;
		}
	}
}

void	print_flag_str(t_prn *prn, int len)
{
	int	i;
	char	sign;

	sign = (prn->sign == 1) ? '-' : '+';
	if ((prn->fl_plus == 1 || prn->sign == 1) && prn->fl_minus == 0)
	{
		prn->width -= 1;
		if (prn->fl_zero == 1)
			ft_putchar(sign);
	}
	i = 0;
	while (i++ < (prn->width - len))
	{
		if (prn->fl_zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	if ((prn->fl_plus == 1 || prn->sign == 1) && prn->fl_minus == 0 && prn->fl_zero == 0)
		ft_putchar(sign);
}

int		print_format(t_prn *prn, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (prn->width < len)
		prn->width = (prn->sign == 0) ? len : (len + 1);
	if (prn->fl_minus == 1)
	{
		if (prn->fl_plus == 1 || prn->sign == 1)
		{
			if (prn->sign == 1)
				ft_putchar('-');
			else
				ft_putchar('+');
			prn->width --;
		}
		ft_putstr(str);
		print_flag_str(prn, len);
	}
	else
	{
		print_flag_str(prn, len);
		ft_putstr(str);
	}
	prn->width += (prn->sign == 0) ? 0 : 1;
	printf("|size = %d|\n", prn->width);
	return (prn->width);
}

void add_point(char *str, t_prn *prn, int degree)
{
	int	len;
	int	count;

	count = (prn->type == 'e' || prn->type == 'E' || degree <= 0) ?
			1 : degree + 1;
	len = count + prn->precision;
	str[len + 1] = '\0';
	while (len > (count))
	{
		str[len] = str[len - 1];
		len--;
	}
	str[count] = '.';
	if (prn->type == 'e' || prn->type == 'E')
		add_exp(str, degree, prn);
	if (prn->type == 'g' || prn->type == 'G')
		cut_str(str);
}
