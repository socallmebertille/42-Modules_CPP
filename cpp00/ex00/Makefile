NAME = megaphone

C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

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

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BOLD)$(YELLOW)$(MAIN) Clean rule OK !$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(CYAN)$(MAIN) Fclean rule OK !$(RESET)"

re: fclean all

.PHONY: all clean fclean re show-main