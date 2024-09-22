NAME = a.out
OBJS := main.o test_ft_memcpy.o test_ft_memmove.o test_ft_strlcpy.o test_ft_strlcat.o

.PHONY: clean all fclean

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) ../libft/libft.a -o $(NAME)

%.o : %.c tests_libft.h Makefile
	cc -c $< -o $@ -Wall -Werror -Wextra

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
