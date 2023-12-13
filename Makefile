# Program name
NAME = push_swap
BONUS = checker

# Colors
DEFAULT    = \033[0m
BLACK    = \033[0;30m
RED        = \033[0;31m
GREEN    = \033[0;32m
YELLOW    = \033[0;33m
BLUE    = \033[0;34m
PURPLE    = \033[0;35m
CYAN    = \033[0;36m
BWHITE    = \033[1;37m

# Directories
SRC_DIR = src
STACK_DIR = stack
BONUS_DIR = bonus
OBJ_DIR = obj
LIBFT_DIR = libft

# Files
LIBFT = $(LIBFT_DIR)/libft.a

define LIB :=
	$(LIBFT)
endef
LIB := $(strip $(LIB))

define INCLUDE :=
	include
	$(LIBFT_DIR)/include
endef
INCLUDE := $(strip $(INCLUDE))

define SRC :=
	main.c
	find_median.c
	direction.c
	sort.c
	insertion.c
	lower_cost.c
endef
SRC := $(strip $(SRC))

define STACK_SRC :=
	push.c
	swap.c
	rotate.c
	r_rotate.c
	error.c utils.c
	check.c
endef
STACK_SRC := $(strip $(STACK_SRC))

define BONUS_SRC :=
	bonus.c
	read_ope.c
	kook.c
endef
BONUS_SRC := $(strip $(BONUS_SRC))

OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
STACK_OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(STACK_SRC))
BONUS_OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(BONUS_SRC))

# Utils
CC = clang
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
INCLUDE_FLAGS := $(addprefix -I , $(INCLUDE))
LIB_FLAGS = --no-print-directory --silent
WD = Working directory:

# Rules
.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(STACK_OBJ) $(OBJ)
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(STACK_OBJ) $(OBJ) $(LIB) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(CYAN)- Compiling$(DEFAULT) $<"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo "$(RED)! Removing$(DEFAULT) $(OBJ_DIR) files"
	@$(RM) $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	@echo "$(RED)! Removing$(DEFAULT) $(NAME)"
	@$(RM) $(NAME)

bclean: clean
	@echo "$(RED)! Removing$(DEFAULT) $(BONUS)"
	@$(RM) $(BONUS)

.PHONY: re
re: fclean all

$(LIBFT):
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

.PHONY: cleanlib
cleanlib:
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make clean -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

.PHONY: fcleanlib
fcleanlib:
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make fclean -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

.PHONY: relib
relib:
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make fclean -C $(LIBFT_DIR) $(LIB_FLAGS)
	@make -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

.PHONY:
bre: bclean bonus

.PHONY: bonus
bonus: $(LIBFT) $(STACK_OBJ) $(BONUS_OBJ)
	@echo "* Assembling $(BONUS)"
	@$(CC) $(CFLAGS) $(STACK_OBJ) $(BONUS_OBJ) $(LIB) -o $(BONUS)

.PHONY: norm
norm:
	@norminette $(SRC_DIR) | awk '/Error/'
	@norminette $(INCLUDE) | awk '/Error/'
