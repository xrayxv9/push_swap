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
SRC_PATH = utils/

SRC = main.c parsing.c ft_utils_node_remains.c ft_utils_node.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)
	@echo "$(BLUE)Compilation terminée"
	@echo "$(RESET)"

$(PRINTF):
	@make --no-print-directory -C $(PRINTF_DIR)

$(NAME): $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
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
