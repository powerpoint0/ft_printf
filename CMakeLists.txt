cmake_minimum_required(VERSION 3.15)
project(ft_printf5 C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft/includes)

add_executable(ft_printf5
		includes/ft_printf.h
		libft/includes/libft.h
		libft/src/ft_atoi.c
		libft/src/ft_bzero.c
		libft/src/ft_isalnum.c
		libft/src/ft_isalpha.c
		libft/src/ft_isascii.c
		libft/src/ft_isdigit.c
		libft/src/ft_isprint.c
		libft/src/ft_itoa.c
		libft/src/ft_lstadd.c
		libft/src/ft_lstaddback.c
		libft/src/ft_lstdel.c
		libft/src/ft_lstdelone.c
		libft/src/ft_lstiter.c
		libft/src/ft_lstlast.c
		libft/src/ft_lstmap.c
		libft/src/ft_lstnew.c
		libft/src/ft_lstrevers.c
		libft/src/ft_lstsize.c
		libft/src/ft_memalloc.c
		libft/src/ft_memccpy.c
		libft/src/ft_memchr.c
		libft/src/ft_memcmp.c
		libft/src/ft_memcpy.c
		libft/src/ft_memdel.c
		libft/src/ft_memmove.c
		libft/src/ft_memset.c
		libft/src/ft_putchar.c
		libft/src/ft_putchar_fd.c
		libft/src/ft_putendl.c
		libft/src/ft_putendl_fd.c
		libft/src/ft_putnbr.c
		libft/src/ft_putnbr_fd.c
		libft/src/ft_putstr.c
		libft/src/ft_putstr_fd.c
		libft/src/ft_strcat.c
		libft/src/ft_strchr.c
		libft/src/ft_strclr.c
		libft/src/ft_strcmp.c
		libft/src/ft_strcpy.c
		libft/src/ft_strdel.c
		libft/src/ft_strdup.c
		libft/src/ft_strequ.c
		libft/src/ft_striter.c
		libft/src/ft_striteri.c
		libft/src/ft_strjoin.c
		libft/src/ft_strlcat.c
		libft/src/ft_strlen.c
		libft/src/ft_strmap.c
		libft/src/ft_strmapi.c
		libft/src/ft_strncat.c
		libft/src/ft_strncmp.c
		libft/src/ft_strncpy.c
		libft/src/ft_strnequ.c
		libft/src/ft_strnew.c
		libft/src/ft_strnstr.c
		libft/src/ft_strrchr.c
		libft/src/ft_strsplit.c
		libft/src/ft_strstr.c
		libft/src/ft_strsub.c
		libft/src/ft_strtrim.c
		libft/src/ft_tolower.c
		libft/src/ft_toupper.c
		libft/src/get_next_line.c
		srcs/ft_printf.c
		srcs/print_cs.c
		srcs/print_d.c
		srcs/print_efg.c
		srcs/print_f_func.c
		srcs/print_oux_p.c
		srcs/set_flags_n_mods.c
		srcs/utils.c
		srcs/additional_func.c
		main.c)
