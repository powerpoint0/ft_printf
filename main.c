#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	long int		k;
	int		size;
	char	*str;
	char a = 'a';
	unsigned long long int i = 4294967295;
	//float i = 3.999;
	int ptr[2] ={4} ;

	//i = 0;
	k = 2147483649;
	size = 10;
	str = "tesst";
	i = i*2 ;
	//ft_printf("text %p", &str);
	//printf("\ntexo %p\n", &str);

	ft_printf("\ntext %15p\n", &ptr);
	printf("\ntexo %15p\n", &ptr);

	ft_printf("\ntext %-20p\n", &ptr);
	printf("\ntexo %-20p\n", &ptr);
	ft_printf("\ntext %-15p\n", ptr);
	printf("\ntexo %-15p\n", ptr);
	ft_printf("\ntext %-15p\n", &a);
	printf("\ntexo %-15p\n", &a);

	//ft_printf("\ntext %6s\n", str);
	//printf("\ntexo %6s\n", str);
	//ft_printf("text %-15.40hx", i);
	//printf("\ntexo %-15.40hx\n", i);
	//ft_printf("\ntext %llx\n", i);
	//printf("\ntexo %llx\n", i);

	//ft_printf("text %20.0llX", i);
	//printf("\ntexo %20.0llX\n", i);

	//ft_printf("text % +30f",0);
	//printf("\ntexo % +30f\n", 0);
	//ft_printf("text %#020x", i);   //c x
	//printf("\ntexo %#020x\n", i);

	//ft_printf("text %020X", i);
	//printf("\ntexo %020X\n",i);
	ft_printf("text %20llx", i);
	printf("\ntexo %20llx\n",i);

	//ft_printf("\ntext\n %% \taaa\r\v\f %-10.3s aaa", str);
	//printf("\ntext\n %% \taaa\r\v\f %-10.3s aaa", str);
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


//ft_printf("\nlTextt %% %5.15d, %s\n", i, "rText");
//printf("\nlTexto %% %5.15d, %s\n", i, "rText");
//ft_printf("\nlText %% %10s, %d\n", "rText", i);
//printf("\nlText %% %10s, %d\n", "rText", i);
//printf("%01.5ld\n", i);
return (0);
}