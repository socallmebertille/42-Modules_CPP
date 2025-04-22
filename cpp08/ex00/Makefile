NAME		=	easyfind

C			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS_NAMES  = 	main.cpp
OBJS_NAMES  =	$(SRCS_NAMES:.cpp=.o)

SRC_DIR		=	srcs
OBJ_DIR		=	objs

SRCS		=	$(addprefix $(SRC_DIR)/,$(SRCS_NAMES))
OBJS		=	$(addprefix $(OBJ_DIR)/,$(OBJS_NAMES))

CYAN		=	\033[38;5;45m
PINK		=	\033[38;5;213m
GREEN		=	\033[32m
YELLOW		=	\033[38;5;220m
RESET		=	\033[0m
BOLD		=	\033[1m
MAIN		=	↻

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BOLD)$(PINK)Compilation $(NAME)...$(RESET)"
	@$(C) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD)$(GREEN)$(MAIN) OK !$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(PINK)Compiling $<...$(RESET)"
	@$(C) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BOLD)$(YELLOW)$(MAIN) Clean rule OK !$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(CYAN)$(MAIN) Fclean rule OK !$(RESET)"

re: fclean all

.PHONY: all clean fclean re