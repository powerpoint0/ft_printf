#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int		i;
	int		size;
	char	*str;
	char a = 'a';
	int k = 7;
	int ptr[2] ={4} ;


//char ptr[2] ={"io"};


	i = -2147483647;
	size = 10;
	str = "tesst";
	//ft_printf("text %p", &str);
	//printf("\ntexo %p\n", &str);

	//ft_printf("\ntext %15p\n", &ptr);
	//printf("\ntexo %15p\n", &ptr);

	//ft_printf("\ntext %-20p\n", ptr);
	//printf("\ntexo %-20p\n", ptr);
	//ft_printf("\ntext %-15p\n", ptr);
	//printf("\ntexo %-15p\n", ptr);
	//ft_printf("\ntext %-15p\n", a);
	//printf("\ntexo %-15p\n", a);

	//ft_printf("\ntext %6p\n", i);
	//printf("\ntexo %6p\n", i);
	//ft_printf("text %x", k);
	printf("\ntexo %#x\n", k);
	printf("\ntexo %x\n", k);
	printf("\ntexo %#X\n", k);
	printf("\ntexo %X\n", k);

	//ft_printf("text %010.3d", i);
	//printf("\ntexo %010.15d\n", i);

	ft_printf("text %15.3d", i);
	printf("\ntexo %15.3d\n", i);
	//ft_printf("text %15.12d", i);
	//printf("\ntexo %-15.12d\n", i);

	//ft_printf("text %08.11d", i);
	//printf("\ntexo %08.11d\n",i);

	//ft_printf("\ntext\n %% \taaa\r\v\f % #-010.3s aaa", str);
	//printf("\ntext\n %% \taaa\r\v\f % #-010.3s aaa", str);
	//printf("\ntext\t %%% #-010.3s\n", str);
	//printf("\ntext %%% \n#-010.3s\n", str);
	//printf("\ntext\r %%% #-010.3s\n", str);
	//printf("\ntext \v%%% #-010.3s\n", str);
	//printf("\ntext \f%%% #-010.3s\n", str);

	/*ft_printf("text %c", a);
	printf("\ntext %c\n", a);
	ft_printf("\ntext %10c", a);
	printf("\ntext %10c\n", a);
	ft_printf("\ntext %% \t%-10c aaa %c", a, a);
	printf("\ntext %% \t%-10c aaa %c\n", a, a);*/

	//ft_printf("%15d", i);
	//printf("\n%018.13d", i);


//ft_printf("\nlTextt %% %5.105d, %s\n", i, "rText");
//printf("\nlTexto %% %5.105d, %s\n", i, "rText");
//ft_printf("\nlText %% %10s, %d\n", "rText", i);
//printf("\nlText %% %s, %d\n", "rText", i);
//printf("%01.5ld\n", i);
return (0);
}