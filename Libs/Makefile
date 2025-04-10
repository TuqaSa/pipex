NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include

# Directory structure
SRC_DIR = src
OBJ_DIR = obj
LIBFT_SRC_DIR = $(SRC_DIR)/libft
PRINTF_SRC_DIR = $(SRC_DIR)/ft_printf

# Source files
LIBFT_SRC = ft_isalpha.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_bzero.c ft_isalnum.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strlen.c ft_strnstr.c \
			ft_memmove.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
			ft_atoi.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strmapi.c ft_striteri.c

PRINTF_SRC = ft_printf.c ft_printhex.c ft_printnum.c ft_printp.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

# Object files
LIBFT_OBJ = $(addprefix $(OBJ_DIR)/libft/, $(LIBFT_SRC:.c=.o))
PRINTF_OBJ = $(addprefix $(OBJ_DIR)/ft_printf/, $(PRINTF_SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/libft/, $(BONUS_SRC:.c=.o))

# All objects
OBJS = $(LIBFT_OBJ) $(PRINTF_OBJ)
ALL_OBJS = $(OBJS) $(BONUS_OBJ)

# Pretty output prefixes
LIBFT_PREFIX = "[LIBFT]"
PRINTF_PREFIX = "[PRINTF]"

# Default target
all: $(NAME)

# Create object files
$(OBJ_DIR)/libft/%.o: $(LIBFT_SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/libft
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(LIBFT_PREFIX) Compiling: $<"

$(OBJ_DIR)/ft_printf/%.o: $(PRINTF_SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/ft_printf
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(PRINTF_PREFIX) Compiling: $<"

# Create library
$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(LIBFT_PREFIX) Library created: $(NAME)"

# Include bonus files
bonus: $(OBJS) $(BONUS_OBJ)
	@ar -rcs $(NAME) $(ALL_OBJS)
	@echo "$(LIBFT_PREFIX) Library with bonus created: $(NAME)"

# Clean targets
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(LIBFT_PREFIX) Cleaning objects"

fclean: clean
	@rm -f $(NAME)
	@echo "$(LIBFT_PREFIX) Cleaning library"

re: fclean all

.PHONY: all clean fclean re bonus