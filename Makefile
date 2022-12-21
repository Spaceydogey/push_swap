.SILENT:
NAME = push_swap

FILES = sort.c algo_utils1.c algo_utils2.c algo_utils3.c algo_utils4.c sort_b.c sort_a.c libft_utils1.c libft_utils2.c list_utils1.c\
		list_utils2.c main.c  mouvement.c operations1.c operations2.c operations3.c parsing.c ft_split.c chunk.c chunk2.c chunk3.c chunk4.c\
		operations_chunk1.c operations_chunk2.c operations_chunk3.c utils.c

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
		$(PRINT) "$(CYAN)making:\t$(NOCOLOR)$(NAME)"
		$(CC) $(CFLAGS) $(FFLAGS) $(OBJ) -o $(NAME)
		$(PRINT) "$(GREEN)done:\t$(NOCOLOR)$(NAME)"

.c.o:
		$(CC) $(CLFAGS) $(FFLAGS) -c $< -o $(<:.c=.o) 

###__RULES__###
all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
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
