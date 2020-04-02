#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

#define B_SIZE 32

typedef struct	s_prn
{
	va_list		ap;
	int			fl_minus;
	int			fl_plus;
	int			fl_space;
	int			fl_sharp;
	int			fl_zero;
	int 		width; // + *;
	int 		precision; // + *;
	int 		mod_h;
	int 		mod_hh;
	int 		mod_l;
	int 		mod_ll;
	int 		mod_L;
	int 		size;
}				t_prn;

int ft_printf(const char *format, ...);
int print_d(t_prn *prn);
int print_s(t_prn *prn);
int print_c(t_prn *prn);

int print_txt(const char *format, int size);

#endif //FT_PRINTF_FT_PRINTF_H
