#include "ft_printf.h"
#include <stdio.h>

double	dabs(double a)
{
	if (a < 0.0f)
		return (-a);
	else
		return (a);
}

int		iabs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int		ft_islower(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	if (ch >= 'A' && ch <= 'Z')
		return (0);
	else
		return (-1);
}

long long int	dt(int degree)
{
	if (degree-- > 0)
		return (10 * dt(degree));
	else
		return (1);
}

void	ft_itoa_unsigned(int num, char *str, int precision)
{
	int			size;
	int			count;
	long int	tmp;

	size = 1;
	tmp = num;
	while (tmp /= 10)
		size++;
	count = ft_strlen(str);
	while (precision > size)
	{
		str[count++] = '0';
		precision--;
	}
	while (size--)
	{
		str[size] = (iabs(num) % 10) + '0';
		num /= 10;
	}
}
