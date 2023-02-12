
LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: push_swap.c checker.c ${LIBFT}
	${CC} push_swap.c checker.c checker_utils.c stack_utils.c ${LIBFT} -o push_swap ${CFLAGS}

${LIBFT}:
		make -C libft
		make bonus -C libft




clean: all
	make clean -C libft

fclean: all
	make fclean -C libft
	${RM} push_swap