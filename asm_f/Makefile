NAME = asm

SRC_DIR = ./asm_src/
OBJ_DIR = ./asm_obj/
INC_DIR = ./asm_inc/
LIB_DIR = ./libft/

SRC =   binary_writer.c \
        check_arg.c \
        check_instruction.c \
        check_label.c \
        copy_header.c \
        error.c \
        free.c \
        init.c \
        main.c \
        parse_instruct.c \
        parsing.c \
        write_octal.c \
        writer.c \

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIB_DIR)libft.a
LIBFT_INC = $(LIB_DIR)includes/
LIBFT_FLAGS = -lft -L $(LIB_DIR)

CC_FLAGS = -Wall -Wextra -Werror
CC = gcc

HEADER_FLAGS = -I $(INC_DIR) -I $(LIBFT_INC)

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT_FLAGS) -o $(NAME)
	@mv $(NAME) ../$(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIB_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIB_DIR)

fclean: clean
	@rm -f ../$(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
