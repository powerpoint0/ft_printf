#include "ft_printf.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	long int		k;
	int		size;
	char	*str;
	//char *filename;
	char a = 'a';
	unsigned long long int i = 4294967295;
	//float i = 3.999;
	int ptr[2] ={4} ;

	//i = 0;
	k = 214;
	size = 10;
	str = "tesst";
	i = i*3 ;
	int fd;

	//ft_printf("text %p", &str);
	//printf("\ntexo %p\n", &str);

	//ft_printf("\ntext %15p\n", &ptr);
	//printf("\ntexo %15p\n", &ptr);

	//ft_printf("\ntext %-20p\n", &ptr);
	//printf("\ntexo %-20p\n", &ptr);
	//ft_printf("\ntext %-15p\n", ptr);
	//printf("\ntexo %-15p\n", ptr);
	//ft_printf("\ntext %-15p\n", &a);
	//printf("\ntexo %-15p\n", &a);

	//ft_printf("\ntext %6s\n", str);
	//printf("\ntexo %6s\n", str);
	//fd = open (argv[1], O_WRONLY | O_CREAT , 0600);
	ft_printf("text %>-*.*x",1, 15, 40, i);
	printf("\ntexo %-*.*x\n", 15, 40, i);
	//ft_printf("\ntext %llo\n", k);
	//printf("\ntexo %llo\n", k);

	//ft_printf("text %20.0llX", k);
	//printf("\ntexo %20.0llX\n", k);

	//ft_printf("text % +30f",0);
	//printf("\ntexo % +30f\n", 0);
	//ft_printf("text %#020x", i);   //c x
	//printf("\ntexo %#020x\n", i);

	//ft_printf("text %020X", i);
	//printf("\ntexo %020X\n",i);
	ft_printf("text %>*c",1, 20, a);
	printf("\ntexo %*c\n", 20,a);

	printf("le fichier {cyan} %s {eoc} contient : {red} %s {eoc}", argv[1], str );
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
//close(fd);
return (0);
}