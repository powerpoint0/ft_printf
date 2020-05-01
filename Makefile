NAME = libftprintf.a

source_dirs := srcs libft/src includes libft/includes

obj_dirs = .

search_wildcards := $(addsuffix /*.c,$(source_dirs))

all: $(NAME)

%.o: %.c
		gcc -c -MD $(addprefix -I,$(source_dirs)) $< -o $@

$(NAME): $(notdir $(patsubst %.c,%.o,$(wildcard $(search_wildcards))))
		ar rc $(NAME) $?
		ranlib $(NAME)

VPATH := $(source_dirs)

clean:
	rm -rf $(addsuffix /*.o,$(obj_dirs))
	rm -rf $(addsuffix /*.d,$(obj_dirs))

fclean: clean
	rm -rf $(NAME)

re: fclean all

include $(wildcard *.d)
