NAME = push_swap

RM_DIR = rm -rf

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

HEADER_1 = header/push_swap.h

HEADER_2 = ctm/ctm_libs/ctm_libs.h

SRCS_DIR = source/

OBJ_DIR = obj/

LIB_DIR = ctm/lib/

LIB = ctm_libs.a

MOVES_DIR = moves/

LIB_PATH = $(LIB_DIR)$(LIB)

SRCS_FILES = init.c main.c till_five.c push.c rotate.c swap.c rev_rotate.c move_printer.c error_msg.c main_sort.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

O_SRCS = $(addprefix $(OBJ_DIR), $(SRCS_FILES:.c=.o))

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c $(HEADER_1) $(HEADER_2)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIB_PATH) $(NAME)

$(LIB_PATH): check_if_exist

$(NAME): $(SRCS) $(O_SRCS)
	clear
	$(MAKE) -C ctm all
	$(CC) $(CFLAGS) $(O_SRCS) -o $(NAME) $(LIB_DIR)$(LIB)
	clear

check_if_exist:
	if [ -d "$(LIB_DIR)" ]; then \
		$(MAKE) -C ctm fclean; \
	fi
	clear

clean:
	$(MAKE) -C ctm/ clean
	$(RM_DIR) $(OBJ_DIR)
	$(RM) $(O_SRCS)
	clear

fclean: clean 
	$(RM_DIR) $(LIB_DIR)
	$(RM) $(NAME)
	clear

re: fclean all
	clear

norm:
	norminette *

.PHONY: all clean fclean re push norm