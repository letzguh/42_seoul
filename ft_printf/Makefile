NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
SRCS = \
		ft_itoa_base.c \
		ft_print_cs.c \
		ft_print_di.c \
		ft_print_p.c \
		ft_print_percent.c \
		ft_print_u.c \
		ft_print_xx.c \
		ft_treat_type.c \
		ft_printf.c \
		ft_parse_options.c
		
OBJS = $(SRCS:.c=.o)
all : $(NAME)
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	make -C libft
	mv libft/libft.a ./$(NAME)
	$(AR) $@ $^
clean :
	rm -f $(OBJS)
	make clean -C libft
fclean : clean
	rm -f $(NAME)
	make fclean -C libft
re : fclean all
.PHONY: all clean fclean re