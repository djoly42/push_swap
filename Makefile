
NAME  = push_swap

CC = gcc

FLAGS = #-Wall -Werror -Wextra

LIB = Lib/libftprintf.a

HEAD = Includes/

SRC = init.c init2.c main.c solve.c solve1.c solve2.c test.c tools.c tools2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB):
	make -C Lib/ fclean
	make -C Lib/

$(NAME):$(LIB) $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	make -C Lib/ fclean

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all
