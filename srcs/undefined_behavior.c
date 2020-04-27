#include "ft_printf.h"

int	ft_undefined_b_flags(t_prn *prn)
{
	if (prn->fl_sharp && (!(prn->type == 'x' || prn->type == 'X' || prn->type == 'o')))
	{
		write(prn->fd, "undefined behavior: flag # doesn't use with type ", 49);
		write(prn->fd, &prn->type, 1);
		return(-1);
	}
	return(0);
}

int	ft_undefined_b_length(t_prn *prn)
{
	if ((prn->mod_ll || prn->mod_l || prn->mod_h || prn->mod_hh || prn->mod_L) &&
		(prn->type == 'c' || prn->type == 's' || prn->type == 'p'))
	{
		write(prn->fd, "undefined behavior: length modifier doesn't use with type ", 58);
		write(prn->fd, &prn->type, 1);
		return(-1);
	}
	if (prn->mod_L && (!(prn->type == 'f' || prn->type == 'e' || prn->type == 'g')))
	{
		write(prn->fd, "undefined behavior: length modifier L doesn't use with type ", 60);
		write(prn->fd, &prn->type, 1);
		return(-1);
	}
	if ((!(prn->mod_L || prn->mod_l)) && (prn->type == 'f' || prn->type == 'e' || prn->type == 'g'))
	{
		write(prn->fd, "undefined behavior: this length modifier doesn't use with type ", 63);
		write(prn->fd, &prn->type, 1);
		return(-1);
	}
	return(0);
}
int	ft_undefined_behavior(t_prn *prn)
{
	if((ft_undefined_b_flags(prn)) < 0)
		return(-1);
	if (prn->precision >= 0 &&(prn->type =='c' || prn->type =='p'))
	{
		write(prn->fd, "undefined behavior: precision doesn't use with type ", 51);
		write(prn->fd, &prn->type, 1);
		return(-1);
	}
	if((ft_undefined_b_length(prn)) < 0)
		return(-1);
	return(0);
}