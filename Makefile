.SILENT:
NAME = push_swap

FILES = algo.c algo_utils.c algo_utils2.c algo_utils3.c libft_utils.c  list_utils.c  main.c  mouvement.c  operations.c  parsing.c

#SRCS = $(addprefix src, $(FILES))
SRCS = $(FILES)

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

FFLAGS = -fsanitize=address -g

CC = @cc

RM = @rm -f

DETECTED_OS = $(shell uname)

###__COMPILATION__###
$(NAME): $(OBJ)
		$(PRINT_OS)
		@make -C libft
		$(PRINT) "$(CYAN)making:\t$(NOCOLOR)$(NAME)"
		$(CC) $(CFLAGS) $(FFLAGS) $(OBJ) -o $(NAME) libft/libft.a
		$(PRINT) "$(GREEN)done:\t$(NOCOLOR)$(NAME)"

.c.o:
		$(CC) $(CLFAGS) $(FFLAGS) -c $< -o $(<:.c=.o) 

###__RULES__###
all: $(NAME)

clean:
		@make clean -C libft
		$(RM) $(OBJ)

fclean: clean
		@make fclean -C libft
		$(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re

###################################################################################################
############################################MISC###################################################
###################################################################################################

###__PRINT__###

PRINT = echo

# endif
PRINT_OS = echo "$(CYAN)OS:\t$(NOCOLOR)$(DETECTED_OS)"

###__COLORS__###
NOCOLOR = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;32m
BLUE = \033[0;34m
CYAN = \033[0;36m
