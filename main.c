#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int		i;
	int		size;
	char	*str;

	i = 10;
	size = 10;
	str = "test";
	ft_printf("text %s %hls", str, str);
//printf("%d", i);
//ft_printf("\nlText %% %010.105ld, %s\n", i, "rText");
//printf("\nlText %% %010.105ld, %s\n", i, "rText");
//ft_printf("\nlText %% %10s, %d\n", "rText", i);
//printf("\nlText %% %s, %d\n", "rText", i);
//printf("%01.5ld\n", i);
}