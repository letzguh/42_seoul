NAME	= cub3D

SRC_NAME = main.c \
		   init.c \
		   exit.c \
		   get_next_line.c \
		   key_event.c\
		   parse_config.c\
		   parse_line.c \
		   parse_utils.c \
		   parse_utils2.c \
		   texture.c \
		   move_player.c \
		   calc_raycasting.c \
		   calc_sprite.c \
		   calc_utils.c \
		   check_map.c \
		   draw.c \
		   free.c \
		   screenshot.c
SRC_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<

BSRC_NAME = main_bonus.c \
		   init_bonus.c \
		   exit_bonus.c \
		   get_next_line_bonus.c \
		   key_event_bonus.c\
		   parse_config_bonus.c\
		   parse_line_bonus.c \
		   parse_utils_bonus.c \
		   parse_utils2_bonus.c \
		   texture_bonus.c \
		   move_player_bonus.c \
		   calc_raycasting_bonus.c \
		   calc_sprite_bonus.c \
		   calc_utils_bonus.c \
		   check_map_bonus.c \
		   draw_bonus.c \
		   free_bonus.c \
		   screenshot_bonus.c\
		   music_bonus.c\
		   meet_flounder.c
BSRC_PATH = ./bonus
BSRC = $(addprefix $(BSRC_PATH)/, $(BSRC_NAME))

BOBJ_NAME = $(BSRC_NAME:.c=.o)
BOBJ_PATH = ./bobj
BOBJ = $(addprefix $(BOBJ_PATH)/, $(BOBJ_NAME))
$(BOBJ_PATH)/%.o: $(BSRC_PATH)/%.c
	@mkdir $(BOBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<

SCREENSHOT = screenshot.bmp

HEADER	= -I./includes

CFLAG	= -Wall -Wextra -Werror

LIBFT	= libft.a

LIBMLX	= libmlx.a

MLX	= -framework OpenGL -framework Appkit

LIBS	= -L./lib/libft -lft -L./lib/minilibx -lmlx

RM	= rm -rf

all	: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(LIBMLX)
	gcc -o $(NAME) $(OBJ) $(HEADER) $(CFLAG) $(LIBS) $(MLX)

bonus	: $(BOBJ) $(LIBFT) $(LIBMLX)
	gcc -o $(NAME) $(BOBJ) $(HEADER) $(CFLAG) $(LIBS) $(MLX)

$(LIBFT):
	$(MAKE) -C lib/libft

$(LIBMLX):
	$(MAKE) -C lib/minilibx

clean	:
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/minilibx clean
	rm -rf $(OBJ_PATH) $(BOBJ_PATH) $(SCREENSHOT)

fclean	: clean
	$(MAKE) -C lib/libft fclean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all clean fclean re
