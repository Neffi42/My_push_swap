NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
INCLUDE = include/
SRC_DIR = src
SRC = ${addprefix ${SRC_DIR}/, main.c push.c swap.c\
		rotate.c r_rotate.c error.c utils.c median.c\
		direction.c check.c sort.c insertion.c lower_cost.c}
OBJ_DIR = obj
OBJ = ${addprefix ${OBJ_DIR}/, ${SRC:.c=.o}}
LIB_DIR = libft
LIB = libft.a

all: ${NAME}

${NAME}: ${OBJ}
	@make -C ${LIB_DIR}
	@echo "* Assembling $@"
	@${CC} ${CFLAGS} ${OBJ} -o $@ ${LIB_DIR}/${LIB}

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${OBJ_DIR}/${SRC_DIR}
	@${CC} ${CFLAGS} -c $< -I ${INCLUDE} -o $@
	@echo "- Compiling $<"

clean:
	@make clean -C ${LIB_DIR}
	@echo "! Removing ${OBJ_DIR} files"
	@${RM} ${OBJ_DIR}

fclean: clean
	@make fclean -C ${LIB_DIR}
	@echo "! Removing ${NAME}"
	@${RM} ${NAME}

re: fclean all

norm:
	@norminette ${SRC_DIR} | awk '/Error/'

.PHONY = all clean fclean re norm
