NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
INCLUDE = include/
SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, main.c find_median.c\
		direction.c sort.c insertion.c lower_cost.c)
STACK_DIR = stack
STACK_SRC = $(addprefix $(SRC_DIR)/$(STACK_DIR)/, push.c swap.c\
		rotate.c r_rotate.c error.c utils.c check.c)
BONUS_DIR = bonus
BONUS_SRC = $(addprefix $(SRC_DIR)/$(BONUS_DIR)/, main.c read_ope.c\
			kook.c)
OBJ_DIR = obj
STACK_OBJ = $(addprefix $(OBJ_DIR)/, $(STACK_SRC:.c=.o))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))
LIB_DIR = libft
LIB = libft.a

all: $(NAME)

$(NAME): $(LIB_DIR)/$(LIB) $(STACK_OBJ) $(OBJ)
	@echo "* Assembling $@"
	@$(CC) $(CFLAGS) $(STACK_OBJ) $(OBJ) -o $@ $(LIB_DIR)/$(LIB)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(STACK_DIR)
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@
	@echo "- Compiling $<"

$(LIB_DIR)/$(LIB):
	@make -C $(LIB_DIR)

clean:
	@make clean -C $(LIB_DIR)
	@echo "! Removing $(OBJ_DIR) files"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@echo "! Removing $(NAME)"
	@$(RM) $(NAME)

bclean: clean
	@echo "! Removing $(BONUS)"
	@$(RM) $(BONUS)

re: fclean all

bre: bclean bonus

bonus: $(LIB_DIR)/$(LIB) $(STACK_OBJ) $(BONUS_OBJ)
	@echo "* Assembling $(BONUS)"
	@$(CC) $(CFLAGS) $(STACK_OBJ) $(BONUS_OBJ) -o $(BONUS) $(LIB_DIR)/$(LIB)

norm:
	@norminette $(SRC_DIR) | awk '/Error/'
	@norminette $(INCLUDE) | awk '/Error/'

.PHONY = all clean fclean re norm bonus
