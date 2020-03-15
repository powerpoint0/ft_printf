#include "ft_printf.h"

int print_d(t_prn *prn)
{
	ft_putnbr(va_arg(prn->ap, int));
	return (0);
}