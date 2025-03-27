NAME = harl2.0

C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Harl.cpp

OBJS_DIR = objs
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

CYAN = \033[38;5;45m
PINK = \033[38;5;213m
GREEN = \033[32m
YELLOW = \033[38;5;220m
RESET = \033[0m
BOLD = \033[1m
MAIN  = ↻

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BOLD)$(PINK)Compilation $(NAME)...$(RESET)"
	@$(C) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD)$(GREEN)$(MAIN) OK !$(RESET)"

$(OBJS_DIR_WC)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "$(PINK)Compiling $<...$(RESET)\n"
	@$(C) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BOLD)$(YELLOW)$(MAIN) Clean rule OK !$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(CYAN)$(MAIN) Fclean rule OK !$(RESET)"

re: fclean all

.PHONY: all clean fclean re