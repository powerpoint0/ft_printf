#include "ft_printf.h"
#include <stdio.h>

int print_s(t_prn *prn)
{
	int		len;
	int		i;
	char	*str;
	int		size;
	static int k;

	k = 0;
	str = va_arg(prn->ap, char*);
	len = ft_strlen(str);
	size = (prn->width > len) ? prn->width : len;
	i = 0;
	while (i < size)
	{
		if (prn->fl_minus == 0)
		{
			if (i < (size - len) && prn->fl_zero == 1)
				write(1, "0", 1);
			if (i < (size - len) && prn->fl_zero == 0)
				write(1, " ", 1);
			if (i >= (size - len))
				write(1, &str[i - (size - len)], 1);
		}
		if (prn->fl_minus == 1)
		{
			if (i < len)
				write(1, &str[i], 1);
			if (i >= len)
				write(1, " ", 1);
		}
		i++;
	}
	k = k + size;
	printf("|size = %d|", size);
	printf("|k = %d|", k);
	return (size);
}