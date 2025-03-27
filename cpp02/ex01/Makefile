NAME = fixed
NAME_WC = fixedWithComments

C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp
SRCS_WC = mainWithComments.cpp FixedWithComments.cpp

OBJS_DIR = objs
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)
OBJS_DIR_WC = objs_wc
OBJS_WC = $(SRCS_WC:%.cpp=$(OBJS_DIR_WC)/%.o)

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

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "$(PINK)Compiling $<...$(RESET)\n"
	@$(C) $(CFLAGS) -c $< -o $@

with_comments: $(NAME_WC)

$(NAME_WC): $(OBJS_WC)
	@echo "$(BOLD)$(PINK)Compilation $(NAME_WC)...$(RESET)"
	@$(C) $(CFLAGS) $(OBJS_WC) -o $(NAME_WC)
	@echo "$(BOLD)$(GREEN)$(MAIN) OK !$(RESET)"

$(OBJS_DIR_WC)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "$(PINK)Compiling $<...$(RESET)\n"
	@$(C) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR) $(OBJS_DIR_WC)
	@echo "$(BOLD)$(YELLOW)$(MAIN) Clean rule OK !$(RESET)"

fclean: clean
	@rm -f $(NAME) $(NAME_WC)
	@echo "$(BOLD)$(CYAN)$(MAIN) Fclean rule OK !$(RESET)"

re: fclean all

.PHONY: all clean fclean re with_comments