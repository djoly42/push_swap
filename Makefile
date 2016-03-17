
NAME  = pushswap

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB = Lib/libftprintf.a

HEAD = Includes/

SRC = test.c main.c tools.c init.c solve.c 

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

