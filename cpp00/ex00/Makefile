NAME = cub3d
BONUS = cub3d_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS_DIR = srcs
OBJ_DIR = objs
SRCS_DIR_BONUS = srcs_bonus
OBJ_DIR_BONUS = objs_bonus

INCDIR = includes minilibx
LIBFT_DIR = libft

SRCS_NAMES =	main.c \
				check_map_file.c \
				map_file_parse.c \
				get_texture.c \
				recup_color.c \
				check_color.c \
				map_parse.c \
				map_access.c \
				create_rgb.c \
				utils.c \
				free.c \
				render_game.c \
				moves.c \
				put_img.c

OBJS_NAMES = $(SRCS_NAMES:.c=.o)
SRCS = $(addprefix $(SRCS_DIR)/,$(SRCS_NAMES))
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJS_NAMES))


# INCLUDES = $(addprefix -I, $(INCDIR)) -I$(LIBFT_DIR)
# LIBS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft

CYAN = \033[38;5;45m
PINK = \033[38;5;213m
GREEN = \033[32m
YELLOW = \033[38;5;220m
RESET = \033[0m
BOLD = \033[1m
MAIN  = ↻

all: $(NAME)
bonus: $(BONUS)

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "$(BOLD)$(PINK)Compilation $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(BOLD)$(GREEN)$(BIKE_MAIN) OK !$(RESET)"


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

show-main:
	@if [ ! -f .main ]; then echo -n "" > .main; fi
	@echo -n "$(BIKE_MAIN)" >> .main
	@printf "$(CYAN) %s$(RESET)\r" "$$(cat .main)"


$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
	@$(MAKE) --no-print-directory show-bike-main

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BOLD)$(CYAN)$(MAIN) Clean rule OK !$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(BLUE)$(MAIN) Fclean rule OK !$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re show-bike-main show-bike-bonus