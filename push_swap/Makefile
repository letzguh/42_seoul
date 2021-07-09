NAME	= push_swap

SRC_NAME = main.c \
		   error.c 
		
SRC_PATH = ./srcs
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<

HEADER	= -I./includes

CFLAG	= -Wall -Wextra -Werror

LIBFT	= libft.a

PUSHSWAP	= push_swap.a

LIB	= -L./lib/libft -lft 

RM	= rm -rf

all	: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(PUSHSWAP)
	gcc -o $(NAME) $(OBJ) $(HEADER) $(CFLAG) $(LIB) 

$(LIBFT):
	$(MAKE) -C lib/libft

clean	:
	$(MAKE) -C lib/libft clean
	rm -rf $(OBJ_PATH)

fclean	: clean
	$(MAKE) -C lib/libft fclean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all clean fclean re