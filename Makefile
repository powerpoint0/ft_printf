source_dirs := . srcs libft/src includes libft/includes

    search_wildcards := $(addsuffix /*.c,$(source_dirs))

    iEdit: $(notdir $(patsubst %.c,%.o,$(wildcard $(search_wildcards))))
		gcc $^ -o $@

    VPATH := $(source_dirs)

    %.o: %.c
		gcc -c -MD $(addprefix -I,$(source_dirs)) $<

    include $(wildcard *.d)