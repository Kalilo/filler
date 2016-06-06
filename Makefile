NAME = filler
FILES = input_data.txt read.c
HEADER = filler.h
OBJECTS = $(FILES:.c=.o)
CFLAG = -Wall -Werror -Wextra
ATTACH = -L libft/ -lft

all: $(NAME)

quick: clean $(NAME)
	@echo "Made Quickly"

lib:
	@make -C libft/ fclean
	@make -C libft/

$(NAME): lib
	@gcc $(CFLAG) -I libft/ -c $(FILES)
	@gcc $(CFLAG) -o $(NAME) $(HEADER) $(OBJECTS) $(ATTACH)
	@echo "filler Successfully Compiled"

clean:
	@/bin/rm -f $(OBJECTS)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norme:
	@clear
	@norminette $(FILES)

test:
	@./fdf ../collab_fdf/test_maps/42.fdf
