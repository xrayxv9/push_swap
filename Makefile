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
SORT_PATH = sort/

SORT = pre_sort.c
SRC = main.c
UTIL = push_rotate.c
PARSING = parsing.c ft_utils_node_remains.c ft_utils_node.c parsing2.c gen_utils.c ft_itoa.c

SORTS = $(addprefix $(SORT_PATH), $(SORT))  
SRCS = $(addprefix $(SRC_PATH), $(SRC))
PARSINGS = $(addprefix $(PARSING_PATH), $(PARSING))
UTILS = $(addprefix $(UTIL_PATH), $(UTIL))

OBJ = $(PARSING:.c=.o)
OBJ_UTIL = $(UTIL:.c=.o)
OBJ_SRC = $(SRC:.c=.o)
OBJ_SORT = $(SORT:.c=.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_UTIL = $(addprefix $(OBJ_PATH), $(OBJ_UTIL))
OBJS_SRC = $(addprefix $(OBJ_PATH), $(OBJ_SRC))
OBJS_SORT = $(addprefix $(OBJ_PATH), $(OBJ_SORT))

all: $(NAME)
	@echo ">>> $(BLUE)COMPILATION TERMINEE $(RESET)<<<"
	@echo "$(YELLOW) _______           _______                _______           _______  _______ "
	@echo "(  ____ )|\     /|(  ____ \|\     /|     (  ____ \|\     /|(  ___  )(  ____ )"
	@echo "| (    )|| )   ( || (    \/| )   ( |     | (    \/| )   ( || (   ) || (    )|"
	@echo "| (____)|| |   | || (_____ | (___) |     | (_____ | | _ | || (___) || (____)|"
	@echo "|  _____)| |   | |(_____  )|  ___  |     (_____  )| |( )| ||  ___  ||  _____)"
	@echo "| (      | |   | |      ) || (   ) |           ) || || || || (   ) || (      "
	@echo "| )      | (___) |/\____) || )   ( |     /\____) || () () || )   ( || )      "
	@echo "|/       (_______)\_______)|/     \|_____\_______)(_______)|/     \||/       "
	@echo "                                   (_____)                                   $(RESET)"
	@echo "$(RESET)"

$(PRINTF):
	@make --no-print-directory -C $(PRINTF_DIR)

$(NAME): $(PRINTF) $(OBJS) $(OBJS_SORT) $(OBJS_UTIL) $(OBJS_SRC)
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_UTIL) $(OBJS_SORT) $(OBJS_SRC) $(PRINTF) -o $@

$(OBJ_PATH)%.o: $(PARSING_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(SORT_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(UTIL_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo ">>> $(RED)SUPPRESSION DES FICHIERS .o $(RESET)<<<"
	@rm -rf $(OBJ_PATH)
	@make --no-print-directory -C $(PRINTF_DIR) fclean
	@echo "$(RED)"
	@echo "$(RESET)"

fclean: clean
	@echo ">>> $(RED)SUPPRESSION DE L'EXECUTABLE $(RESET)<<<"
	@echo "\n"
	@rm -f $(NAME)
	
re: fclean all
	@echo "$(RESET)"

.PHONY: all clean fclean re
