NAME = push_swap

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

HEADER = push_swap.h

SRC = push_swap.c checker.c checker_utils.c \
		stack_tools0.c stack_tools1.c rules.c small_sort.c\
		big_sort.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME) 

$(LIBFT) :
	make -C libft
	make bonus -C libft

clean :
	make clean -C libft
	$(RM) *.o

fclean : clean
	make fclean -C libft
	$(RM) $(NAME)

re : fclean all





