NAME = filler
FILES = read.c store_arr.c filler.c ft_test_var.c
HEADER = filler.h
OBJECTS = $(FILES:.c=.o)
CFLAG = -Wall -Werror -Wextra
ATTACH = libft/libft.a

all: fclean lib $(NAME)

quick: fclean $(NAME)
	@echo "Made Quickly"

lib:
	@make -C libft/ fclean
	@make -C libft/

$(NAME):
	@gcc $(CFLAG) $(FILES) $(HEADER) $(ATTACH)
	@echo "filler Successfully Compiled"
	@mv a.out $(NAME)

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
	@resources/filler_vm -p1 ./filler -f resources/maps/map00
