NAME = corewar
LIBFT_NAME = libftprintf.a

SRC_PATH = src/
SRC_F_PATH = src/functions/
SRC_SDL_P = src/sdl_f/
SRC_R_P = src/render/
INC_PATH = includes/
LIB_PATH = libft/
ASM_PATH = asm_f/

SRC =           main.c \
                main_utils.c \
                main_cycle.c \
                carriage.c \
                flags.c \
                mtupikov_adds.c \
                parser.c \
                print.c \
                put_bots.c \
                util.c \
                vis.c \
                util_validation.c \
                convert.c \
                bot.c \
                init.c \


SRC_SDL =       sdl_init.c \
                sdl_utils.c \

SRC_FUNCTIONS = live_1.c \
                ld_2.c \
                st_3.c \
                add_4.c \
                sub_5.c \
                bit_operation.c \
                and_6.c \
                or_7.c \
                xor_8.c \
                zjmp_9.c \
                ldi_10.c \
                sti_11.c \
                fork_12.c \
                lld_13.c \
                lldi_14.c \
                lfork_15.c \
                aff_16.c \
                rewrite_bytes.c \
                shift.c \

SRC_RENDER =    render.c \
                intro.c \
                loading.c \
                death_check.c \
                put_frame.c \
                boring_render.c \
                print_info.c \
                winner_render.c \
                sound_loader.c \
                utils_render_1.c \

OBJ_DIR = obj

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_SRC_F = $(addprefix $(OBJ_DIR)/, $(SRC_FUNCTIONS:.c=.o))

OBJ_SRC_SDL_P = $(addprefix $(OBJ_DIR)/, $(SRC_SDL:.c=.o))

OBJ_SRC_R_P = $(addprefix $(OBJ_DIR)/, $(SRC_RENDER:.c=.o))

CC	= gcc
FLG = -Werror -Wextra -Wall

CGFLAGS = -lmlx -framework OpenGL -framework AppKit
INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_SRC_F) $(OBJ_SRC_SDL_P) $(OBJ_SRC_R_P) $(OBJ_SDL)
	@make -C $(LIB_PATH)
	@make -C $(ASM_PATH)
	@$(CC) -O3 $(FLG) $(CGFLAGS) $(FRAMEWORKS) -g $(LIB_PATH)$(LIBFT_NAME) $(OBJ_SRC) $(OBJ_SRC_F) \
	$(OBJ_SRC_SDL_P) $(OBJ_SRC_R_P) $(OBJ_SDL) -o $(NAME)

$(OBJ_DIR)/%.o : ./src/%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLG) $(CFLAGS) -g -I./inc -I./$(SDL_PATH)/include $(INCLUDES) -c -o $@ $<

$(OBJ_DIR)/%.o : ./src/functions/%.c
	@$(CC) $(FLG) $(CFLAGS) -g -I./inc -I./$(SDL_PATH)/include $(INCLUDES) -c -o $@ $<

$(OBJ_DIR)/%.o : ./src/sdl_f/%.c
	@$(CC) $(FLG) $(CFLAGS) -g -I./inc -I./$(SDL_PATH)/include $(INCLUDES) -c -o $@ $<

$(OBJ_DIR)/%.o : ./src/render/%.c
	@$(CC) $(FLG) $(CFLAGS) -g -I./inc -I./$(SDL_PATH)/include $(INCLUDES) -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_PATH) clean
	@make -C $(ASM_PATH) clean


fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@make -C $(ASM_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
