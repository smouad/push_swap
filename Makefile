NAME = push_swap

BNAME = checker

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRC =  $(addprefix mandatory/, args_check0.c args_check1.c \
		stack_tools0.c stack_tools1.c rules.c \
		small_sort.c big_sort.c push_swap.c)

BSRC = $(addprefix bonus/, args_check0.c args_check1.c \
		stack_tools0.c stack_tools1.c \
		rules.c checker.c \
		get_next_line.c get_next_line_utils.c)

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

bonus : $(BNAME)

$(BNAME) : $(BOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) -o $(BNAME)

$(LIBFT) :
	make -C libft
	make bonus -C libft

clean :
	make clean -C libft
	$(RM) $(OBJ) $(BOBJ)

fclean : clean
	make fclean -C libft
	$(RM) $(NAME) $(BNAME)

re : fclean all

