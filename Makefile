SRCDIR = src
INCDIR = include
LIBDIR = libft
OBJDIR = obj
BINDIR = bin
NAME = ./$(BINDIR)/tester
OBJS := main.o test_ft_memcpy.o test_ft_memmove.o test_ft_strlcpy.o test_ft_strlcat.o test_ft_isalpha.o test_ft_isalnum.o test_ft_isascii.o test_ft_isprint.o test_ft_toupper.o test_ft_tolower.o
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))

.PHONY: clean all fclean

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) $(LIBDIR)/libft.a -o $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCDIR)/tests_libft.h Makefile
	cc -c $< -o $@ -Wall -Werror -Wextra

clean:
	rm -rf $(OBJDIR)/$(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
