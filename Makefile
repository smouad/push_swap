
LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

${LIBFT}:	libft
		make -C libft

all: push_swap.c checker.c
	${CC} push_swap.c checker.c ${LIBFT} -o push_swap ${CFLAGS}


clean: all
	make clean -C libft
	${RM} push_swap
fclean: all
	make fclean -C libft
	${RM} push_swap