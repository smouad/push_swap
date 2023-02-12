
LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

${LIBFT}:
		make -C libft
		make bonus -C libft

all: push_swap.c checker.c
	${CC} push_swap.c checker.c checker_utils.c ${LIBFT} -o push_swap ${CFLAGS}


clean: all
	make clean -C libft

fclean: all
	make fclean -C libft
	${RM} push_swap