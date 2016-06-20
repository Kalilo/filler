NAME = filler
FILES = read.c store_arr.c filler.c *weight.c seek.c
FILES += basic_math.c scan_arr.c result.c free_arr.c
HEADER = filler.h
OBJECTS = $(FILES:.c=.o)
CFLAG = -Wall -Werror -Wextra -g
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
	@/bin/rm -f $(OBJECTS) $(HEADER:.h=.h.gch)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norme:
	@clear
	@norminette $(FILES) $(HEADER)

test:
	@resources/filler_vm -p1 ./filler -f resources/maps/map00

testvs:
	@resources/filler_vm -p1 ./filler -p2 ./resources/players/grati.filler -f \
		resources/maps/map00

testvs2:
	@resources/filler_vm -p1 ./resources/players/grati.filler -p2 ./filler -f \
		resources/maps/map00

ftest: fclean all test
	@echo "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"

ftest0: fclean all
	@resources/filler_vm -p1 ./resources/players/abanlin.filler -p2 ./filler \
		-f resources/maps/map00
	@echo "Done Testing"
	
me: qme
	cat -e author
	
qme:
	@rm -Rf author
	@whoami > author
