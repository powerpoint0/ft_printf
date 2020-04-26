#include <stdarg.h>#include <stdio.h>#include "ft_printf.h"int	ft_find_count(const char *s, int c){	int i;	i = 0;	while (s[i] != '\0')	{		if (s[i] == (char)c)			return (i);		i++;	}	if ((char)c == '\0')		return (i);	return (-1);}int	set_flag(const char *format, t_prn *prn, int end){	int		i;	i = 0;	while (i < end && (ft_strchr("-+ #0>", format[i]) != NULL))	{		if (format[i] == '-')			prn->fl_minus = 1;		if (format[i] == '+')			prn->fl_plus = 1;		if (format[i] == ' ')			prn->fl_space = 1;		if (format[i] == '#')			prn->fl_sharp = 1;		if (format[i] == '0')			prn->fl_zero = 1;		if (format[i] == '>')			prn->fd = ft_get_signed_mod_llhh(prn);		i++;	}	if (prn->fl_minus == 1 && prn->fl_zero == 1)		prn->fl_zero = 0;	return (i);}int	find_type(const char *format, t_prn *prn){	int		i;	int 	size;	char	type[16]= "diouxXeEfFgGscp\0";	size = 0;	i = 0;	while(format[size] != type[i])	{		if(format[size] == '\0')			return (-1);		if (type[i] == '\0')		{			i = 0;			size++;		}		else			i++;	}	prn->size = size;	prn->type = format[prn->size];	return (size);}void	clear_format(t_prn *prn){	prn->fl_minus = 0;	prn->fl_plus = 0;	prn->fl_space = 0;	prn->fl_sharp = 0;	prn->fl_zero = 0;	prn->width = 0;	prn->precision = -1;	prn->mod_h = 0;	prn->mod_hh = 0;	prn->mod_l = 0;	prn->mod_ll = 0;	prn->mod_L = 0;	prn->size = 0;	prn->sign = 0;	prn->neg = 0;	prn->fd = 1;	prn->type = '0';}int	set_mod(const char *format, int i, t_prn *prn){	if (format[i] == 'h' && i + 1 == prn->size)		prn->mod_h = 1;	else if (format[i] == 'h' && format[i + 1] == 'h' && i + 2 == prn->size)		prn->mod_hh = 1;	else if (format[i] == 'l' && i + 1 == prn->size)		prn->mod_l = 1;	else if (format[i] == 'l' && format[i + 1] == 'l' && i + 2 == prn->size)		prn->mod_ll = 1;	else if (format[i] == 'L' && i + 1 == prn->size)		prn->mod_L = 1;	else if (i != prn->size)		return(-1);	return (prn->size);}int set_width(const char *format, int i, t_prn *prn){	int	st;	st = i;	//if (prn->fd < 0)	//return(-1);	if (format[i]== '*')	{		prn->width = ft_get_signed_mod_llhh(prn);		i++;	}	else		{		while (i < prn->size && ft_isdigit(format[i]))			i++;		if (i == prn->size || format[i] == '.' || ft_find_count("hlL", format[i]) != -1)			prn->width = ft_atoi(ft_strsub(format, st, i));		else			return (-1);		}	return (i);}int	set_precision(const char *format, int i, t_prn *prn){	int	st;	if (format[i] == '.')	{		i++;		st = i;		while(i < prn->size && ft_find_count("hlL", format[i]) == -1 && (format[i] != '*'))		{			if (ft_isdigit(format[i]) == 0)				return (-1);			i++;		}		if (format[i]== '*')			prn->precision = ft_get_signed_mod_llhh(prn);		else			prn->precision = ft_atoi(ft_strsub(format, st, prn->size));	}	if (prn->precision > 0 && (ft_strchr("diouxX", format[prn->size]) != 0))		prn->fl_zero = 0;	return (i);}int	set_param(const char *format, t_prn *prn){	int	i;	i = 0;	if (((find_type(format, prn)) == -1) ||		(i = set_flag(format, prn, prn->size)) == -1 ||		(i = set_width(format, i, prn)) == -1 ||		((i = set_precision(format, i, prn)) == -1) ||		(set_mod(format, i, prn)) == -1)	{		write(prn->fd, "undefined_behavior: wrong format", 32);		return (-1);	}	//if (ft_undefined_behavior(prn) == -1)		//return(-1);	return (0);}int parsing_type(const char *format, t_prn *prn){	if ((set_param(format, prn)) == -1)		return (-1);	if (format[prn->size] == 'd' || format[prn->size] == 'i')		print_di(prn);	if (format[prn->size] == 's')		print_s(prn);	if (format[prn->size] == 'c')		print_c(prn);	if (format[prn->size] == 'p')		print_p(prn);	if (format[prn->size] == 'o' || format[prn->size] == 'u' ||		format[prn->size] == 'x' ||  format[prn->size] == 'X')		print_ouxX(prn);	if (format[prn->size] == 'f' || format[prn->size] == 'F' ||		format[prn->size] == 'g' || format[prn->size] == 'G' ||		format[prn->size] == 'e' || format[prn->size] == 'E')		print_f(prn);	return (0);}int print_txt(const char *format, int size){	int	i;	i = 0;	while (i < size && format[i] != '\0')	{		ft_putchar(format[i]);		i++;	}	return (0);}int ft_algoritm(const char *format, t_prn *prn){	int		fcount;	while ((fcount = ft_find_count(format, '%')) >= 0)	{		if(format[fcount + 1] == '%')		{			print_txt(format, fcount + 1);			format += fcount + 2;		}		else		{			print_txt(format, fcount);			format += fcount + 1;			if((parsing_type(format, prn)) == -1)				return(-1);			format += prn->size + 1;			clear_format(prn);		}	}	if (*format != '\0')		print_txt(format, ft_find_count(format, '\0'));	return(0);}int ft_printf(const char *format, ...){	t_prn	prn;	clear_format(&prn);	va_start(prn.ap, format);	ft_algoritm(format, &prn);	va_end(prn.ap);	return (0);}