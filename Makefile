NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Couleurs pour les messages
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[38;2;15;101;214m
RESET = \033[0m

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

OBJ_PATH = obj/
PARSING_PATH = parsing/
UTIL_PATH = utils/
SRC_PATH = src/

SRC = main.c
UTIL = push_rotate.c reverse_push.c
PARSING = parsing.c ft_utils_node_remains.c ft_utils_node.c parsing2.c gen_utils.c ft_itoa.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
PARSINGS = $(addprefix $(PARSING_PATH), $(PARSING))
UTILS = $(addprefix $(UTIL_PATH), $(UTIL))

OBJ = $(PARSING:.c=.o)
OBJ_UTIL = $(UTIL:.c=.o)
OBJ_SRC = $(SRC:.c=.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_UTIL = $(addprefix $(OBJ_PATH), $(OBJ_UTIL))
OBJS_SRC = $(addprefix $(OBJ_PATH), $(OBJ_SRC))

all: $(NAME)
	@echo "$(BLUE)Compilation terminée"
	@echo "$(RESET)"

$(PRINTF):
	@make --no-print-directory -C $(PRINTF_DIR)

$(NAME): $(PRINTF) $(OBJS) $(OBJS_UTIL) $(OBJS_SRC)
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_UTIL) $(OBJS_SRC) $(PRINTF) -o $@

$(OBJ_PATH)%.o: $(PARSING_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(UTIL_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Suppression des fichiers objets..."
	@rm -rf $(OBJ_PATH)
	@make --no-print-directory -C $(PRINTF_DIR) fclean
	@echo "$(RED)"
	@echo "$(RESET)"

fclean: clean
	@echo "$(RED)Suppression de l'exécutable..."
	@rm -f $(NAME)
	
re: fclean all
	@echo "$(GREEN)Réinitialisation terminée"
	@echo "$(RESET)"

.PHONY: all clean fclean re
