#include "ft_printf.h"
#include <stdio.h>

int		get_degree(long double *nbr)
{
	int			degree;

	degree = 0;
	if (dabs(*nbr) < 1.0f)
	{
		while (dabs(*nbr) < 1.0f)
		{
			*nbr *= 10;
			degree--;
		}
	}
	else
			while (dabs(*nbr) >= 10.0f)
			{
				degree++;
				*nbr /= 10;
			}
	return (degree);
}

void	add_exp(char *str, int degree, t_prn *prn)
{
	int	count;

	count = ft_strlen(str);
	str[count++] = (ft_islower(prn->type) == 1) ? 'e' : 'E';
	str[count++] = (degree < 0) ? '-' : '+';
	if (iabs(degree) < 10)
	{
		str[count++] = '0';
		str[count] = iabs(degree) + '0';
	}
	else
		ft_itoa_unsigned(degree, str, 0);
}

void	print_flag_str(t_prn *prn, int len)
{
	int	i;
	char	sign;

	sign = (prn->neg == 1) ? '-' : '+';
	if ((prn->fl_plus == 1 || prn->neg == 1) && prn->fl_minus == 0)
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
	if ((prn->fl_plus == 1 || prn->neg == 1) && prn->fl_minus == 0 && prn->fl_zero == 0)
		ft_putchar(sign);
}

void		cut_str(char *str)
{
	int	count;

	count = ft_strlen(str) - 1;
	while (str[count] == '0' || str[count] == '.')
	{
		str[count] = '\0';
		count--;
	}
}

int		print_format(t_prn *prn, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (prn->width < len)
		prn->width = (prn->neg == 0) ? len : (len + 1);
	if (prn->fl_minus == 1)
	{
		if (prn->fl_plus == 1 || prn->neg == 1)
		{
			if (prn->neg == 1)
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
	prn->width += (prn->neg == 0) ? 0 : 1;
	printf("|size = %d|\n", prn->width);
	return (prn->width);
}
