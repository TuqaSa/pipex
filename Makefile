CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = pipex.c parsing.c pipe.c command.c
OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a
INCLUDES = -I$(LIBFT_PATH)

NAME = pipex
all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re