.PHONY: all, clean, fclean, re, obj, red, grn, off

NAME = 21sh

# src / obj files
SRC =   main.c \
		main_loop.c \
		output_functions.c \
		read_buffer.c \
		small_functions.c \
		terminal_mode.c \
		key_handler.c \
		functions_for_move.c \
		functions_for_get_coordinates.c \
		print_functions.c \
		check_params.c \


OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# compiler
CC = gcc
#CFLAGS = -ltermcap
#CFLAGS = -Wextra -Wall -Werror -g
# -fsanitize=address

# ft library
FT = ./libft/
FT_LIB = $(addprefix $(FT), libft.a)
FT_INC = -I ./libft
FT_LNK = ./libft/libft.a

# printf library
PR = ./ft_printf/
PR_LIB = $(addprefix $(PR), libftprintf.a)
PR_INC = -I ./ft_printf
PR_LNK = ./ft_printf/libftprintf.a

# directories
SRCDIR = ./src/
INCDIR = -I ./includes
OBJDIR = ./obj/

all: $(NAME)

$(NAME): obj $(FT_LIB) $(PR_LIB) grn $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(PR_LNK) $(FT_LNK) -lm -lcurses  -o $(NAME)
	@echo "\033[0m"

red:
	@echo "\033[0;31m"

grn:
	@echo "\033[0;32m"

off:
	@echo "\033[0m"

obj:
	@mkdir -p $(OBJDIR)

$(FT_LIB):
	@make -C $(FT)

$(PR_LIB):
	@make -C $(PR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(PR_INC) $(FT_INC) $(INCDIR) -o $@ -c $<

clean: red
	/bin/rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(PR) clean

fclean: clean
	/bin/rm -rf $(NAME)
	@make -C $(FT) fclean
	@make -C $(PR) fclean

re: fclean all
