NAME = push_swap

LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

HEADER = push_swap.h

SRC = push_swap.c checker.c checker_utils.c \
		stack_tools0.c stack_tools1.c rules.c small_sort.c

OBJS	= ${SRC:.c=.o}

all: ${NAME} $(LIBFT)

GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

$(LIBFT): 
		make -C libft
		make bonus -C libft

${NAME}: ${OBJS} ${HEADER}
		@printf "$(CURSIVE)$(YELLOW) 	- Compiling $(NAME)... $(RESET)\n"
		${CC} ${OBJS} ${LIBFT} -o ${NAME}


clean:
	make clean -C libft
	${RM} $(OBJS)

fclean:
	make fclean -C libft
	${RM} push_swap
