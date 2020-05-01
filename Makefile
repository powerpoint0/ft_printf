NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

source_dirs = srcs libft/src includes libft/includes

SRCS = libft/src/ft_atoi.c \
               libft/src/ft_bzero.c   \
               libft/src/ft_isdigit.c  \
               libft/src/ft_itoa.c     \
               libft/src/ft_memalloc.c \
               libft/src/ft_memccpy.c   \
               libft/src/ft_putchar.c   \
               libft/src/ft_putchar_fd.c\
               libft/src/ft_putendl.c \
               libft/src/ft_putendl_fd.c	\
               libft/src/ft_putnbr.c	\
               libft/src/ft_putnbr_fd.c		\
               libft/src/ft_putstr.c	\
               libft/src/ft_putstr_fd.c	\
               libft/src/ft_strchr.c     \
               libft/src/ft_strcmp.c	\
               libft/src/ft_strcpy.c     \
               libft/src/ft_strlen.c	\
               libft/src/ft_strnew.c	\
               libft/src/ft_strsub.c	\
               srcs/ft_printf.c	\
               srcs/print_cs.c	\
               srcs/print_d.c	\
               srcs/print_efg.c	\
               srcs/print_f_func.c	\
               srcs/print_ouxX_p.c	\
               srcs/set_flags_n_mods.c	\
               srcs/utils.c	\

OBJS = $(notdir $(patsubst %.c,%.o,$(SRCS)))

all: $(NAME)

%.o: %.c
		gcc $(FLAGS) -c -MD $(addprefix -I,$(source_dirs)) $< -o $@

$(NAME): $(OBJS)
		ar rc $(NAME) $?
		ranlib $(NAME)

VPATH := $(source_dirs)

clean:
	rm -f $(patsubst %.o,%.d,$(OBJS)) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

include $(wildcard *.d)
