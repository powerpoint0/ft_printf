#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

#define B_SIZE 32

typedef struct	s_prn
{
	va_list		ap;
	int			fl_minus;
	int			fl_plus;
	int			fl_space;
	int			fl_sharp;
	int			fl_zero;
	int 		width;
	int 		precision;
	int 		mod_h;
	int 		mod_hh;
	int 		mod_l;
	int 		mod_ll;
	int 		mod_L;
	int 		size;
	int			sign;
	int 		neg;
	int			fd;
	char 		type;
}				t_prn;

union 			test_nan_union
{
	double 		d;
	uintmax_t 	l;
}				test_nan;

int				main();
int		 		ft_printf(const char *format, ...);
int 			print_di(t_prn *prn);
int 			print_s(t_prn *prn);
int 			print_c(t_prn *prn);
int 			print_p(t_prn *prn);
int 			print_ouxX(t_prn *prn);
int 			print_f(t_prn *prn);

int 			print_txt(const char *format, int size);
void 			ft_print_type_csp(int size,int len,t_prn *prn, char *str);

void			ft_itoa16(intmax_t num, char *rez, int base, char *basee);
void 			ft_print_number(int len, int size,char *str, t_prn *prn);
void			ft_print_flags_numberType(int len, char *str, t_prn *prn);
int				ft_count_len(int len, char *str,t_prn *prn);
intmax_t		ft_get_signed_mod_llhh(t_prn *prn);

long double		get_nbr(t_prn *prn);
void			cut_str(char *str);
int				print_format(t_prn *prn, char *str);
void			add_exp(char *str, int degree, t_prn *prn);
void			ft_itoa_unsigned(int num, char *str, int precision);
long long int	dt(int degree);
int				ft_islower(int ch);
int				iabs(int a);
double			dabs(double a);

#endif //FT_PRINTF_FT_PRINTF_H