NAME = server
CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
INCLUDES = -I includes
OBJS_PATH = objs

SRCS = \
	server.c\
	server_util.c
CLIENT_SRCS = \
	client.c

SRCS_PATH = srcs
OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))
CLIENT_OBJS_NAME = $(CLIENT_SRCS:.c=.o)
CLIENT_OBJS = $(addprefix $(OBJS_PATH)/, $(CLIENT_OBJS_NAME))

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS) $(CLIENT)
	$(CC) $(CFLAGS) -L $(LIBFT_PATH) -lft -o $(NAME) $(OBJS)
$(CLIENT) : $(CLIENT_OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -L $(LIBFT_PATH) -lft -o $(CLIENT) $(CLIENT_OBJS)


all : $(NAME)

clean :
	rm -rf $(OBJS_PATH)
	make -C $(LIBFT_PATH) fclean
fclean : clean
	rm -f $(NAME) $(CLIENT)
re : fclean all

.PHONY: all clean fclean re 
