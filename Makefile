CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = instructions/instructions0.c \
      instructions/instructions1.c \
      instructions/instructions2.c \
      utils/algo_utils0.c \
      utils/algo_utils1.c \
      utils/algo_utils2.c \
      utils/instructions_utils0.c \
      utils/instructions_utils1.c \
      utils/main_utils0.c \
      utils/main_utils1.c \
      utils/sorting_func_utils0.c \
      utils/sorting_func0.c \
      main.c

OBJS = $(SRC:.c=.o)
NAME = push_swap
LIB = ./lib

LDFLAGS = -L$(LIB) -lft
INCLUDES = -I$(LIB)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIB)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS)
