#include "../includes/ft_printf.h"

int		ft_islower(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	if (ch >= 'A' && ch <= 'Z')
		return (0);
	else
		return (-1);
}

void		cut_str(char *str)
{
	int	count;

	count = ft_strlen(str) - 1;
	while (str[count] == '0')
	{
		str[count] = '\0';
		count--;
	}
	if (str[count] == '.')
		str[count] = '\0';
}

int			ft_isnan(long double nbr)
{
	union test_nan_union	tnan;

	tnan.d = (double) nbr;
	if (tnan.l == 0x7FF8000000000000 || tnan.l == 0xFFF8000000000000)
		return (1);
	return (0);
}

int			ft_isinf(long double nbr)
{
	union test_nan_union	tnan;

	tnan.d = (double) nbr;
	if (tnan.l == 0x7FF0000000000000)
		return (1);
	if (tnan.l == 0xFFF0000000000000)
		return (-1);
	return (0);
}

int			nan_inf(long double nbr, t_prn *prn, char *str)
{
	if (ft_isnan(nbr))
	{
		if (ft_islower(prn->type))
			ft_strcpy(str, "nan");
		else
			ft_strcpy(str, "NAN");
		prn->fl_zero = 0;
		prn->fl_plus = 0;
		prn->sign = 0;
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
		prn->sign = 0;
		return (1);
	}
	return (0);
}
