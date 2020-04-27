#include "../includes/ft_printf.h"
#include <stdio.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
	long int		k;
	int		size;
	char	*str = NULL;
	//char *filename;
	char a = 'a';
	long long int i = 9558889;
	float n = 3.999;
	int ptr[2] ={4} ;

	//i = 0;
	k = 214;
	size = 10;

	str = "text %%% #-010.3s";

	//i = i*3 ;
	int fd;


	//ft_printf("text %p", &str);
	//printf("\ntexo %p\n", &str);

	//ft_printf("\ntext %15p\n", &ptr);
	//printf("\ntexo %15p\n", &ptr);

	//ft_printf("\ntext %-20p\n", &ptr);
	//printf("\ntexo %-20p\n", &ptr);
	//ft_printf("\ntext %-15p\n", ptr);
	//printf("\ntexo %-15p\n", ptr);
	//ft_printf("");
	//printf("");
	//ft_printf("\ntext %-15p\n", &a);
	//printf("\ntexo %-15p\n", &a);

	//ft_printf("\ntext %6.s\n", str);
	//printf("\ntexo %6.s\n", str);
	//ft_printf("\ntext %-6.s\n", str);
	//printf("\ntexo %-6.s\n", str);
	//fd = open (argv[1], O_WRONLY | O_CREAT | O_EXCL, 0600);          //O_TRUNK
	//ft_printf(MAGENTA"text %>-*.*llx"END,1, 15,40, i);
	//printf(BLUE"\ntexo %-*.*llx"END"\n", 15, 40, i);
	//ft_printf("\ntext %llo\n", k);
	//printf("\ntexo %llo\n", k);

	//ft_printf("text %# 6.0f", n);
	//printf("\ntexo %# 6.0f\n", n);

	//ft_printf("text % +30f",0);
	//printf("\ntexo % +30f\n", 0);
	//ft_printf("text %#020llx", i);   //c x
	//printf("\ntexo %#020x\n", i);

	//ft_printf("text % +020.5lld", i);
	//printf("\ntexo % +020.5lld\n",i);
	//ft_printf("text %+-*.d hj", fd, 8, i);
	printf(END"\ntexo "CYAN"%+-*.d hj"END"\n",8, i);

	//printf("le fichier "YELLOW" %s "END" contient : "WHITE" %s"END, argv[1], str );
	//ft_printf("\ntext\n %% \taaa\r\v\f %-10.3s aaa", str);
	//printf("\ntext\n %% \taaa\r\v\f %-10.3s aaa", str);
	ft_printf("\nte^xt %-10.s %s %s %s %shjjj\n",1, "tr",  "tr" , "tr" ,"tr", "TR");
	printf( "\ntext %-10.s %s %s %s %shjjj\n", "tr", "tr" ,"tr" , "tr", "TR");
	//printf("\ntext\r %%% #-010.3s\n", str);
	//printf("\ntext \v%%% #-010.3s\n", str);
	//printf("\ntext \f%%% #-010.3s\n", str);

	//ft_printf("text c");
	//ft_printf("text %18Ld", i); //?s neinitializ a
	//printf("\ntexo %18Ld\n", i);
	//ft_printf("\ntext %10c", a);
	//printf("\ntext %10c\n", a);
	//ft_printf("\ntext %% \t%-10c aaa %c %d", a, a, i);
	//printf("\ntext %% \t%-10c aaa %c %d\n", a, a, i);

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