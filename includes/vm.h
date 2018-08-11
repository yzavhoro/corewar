/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 14:15:37 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/28 14:19:07 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libft/includes/ft_printf.h"
# include "op.h"
# include <SDL2/SDL.h>
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
# include "SDL_thread.h"
# include <math.h>
# include <time.h>
# include <fcntl.h>

# define SKIP_SIZE 4
# define EXECUTABLE_CODE_SIZE 4
# define FIELD_SIZE 4096

typedef union			u_size
{
	short				s;
	int					integer;
	unsigned char		b[4];
	char				i[4];
}						t_size;

typedef struct			s_bot
{
	int					id;
	unsigned char		name[PROG_NAME_LENGTH];
	unsigned int		size_code;
	unsigned char		*code;
	unsigned char		comment[COMMENT_LENGTH];
	int					live;
	int					lives;
	int					is_alive;
	struct s_bot		*next;
}						t_bot;

typedef struct			s_carry
{
	int					id;
	int					reg[REG_NUMBER];
	int					pos;
	int					live;
	char				carry;
	int					fun_id;
	unsigned char		bot_id;
	int					fun_cycle;
	unsigned char		codage;
	struct s_carry		*next;
	struct s_carry		*prev;
}						t_carry;

typedef struct			s_cell
{
	unsigned char		c;
	int					is_carry;
	int					player_num;
	int					color;
}						t_cell;

typedef struct			s_flags
{
	char				name;
	int					n;
}						t_flags;

typedef struct			s_map
{
	t_cell				cells[FIELD_SIZE];
	unsigned char		field[FIELD_SIZE];
	char				cell_id[FIELD_SIZE];
	t_bot				*bots;
	int					nbr_live;
	int					cycle;
	int					cycle_to_die;
	int					check_time;
	int					vis_mode;
	char				check;
	struct s_carry		*begin;
	struct s_carry		*end;
	t_flags				flag;
	int					nbr_carries;
	int					map_id[4];
}						t_map;

typedef struct			s_fun
{
	void				(*fun)(t_map *map, t_carry *carry);
	int					cycle;
	int					label;
}						t_fun;

# define SCREEN_WIDTH		1920
# define SCREEN_HEIGHT		1080
# define MAP_SIZE			64
# define MAX_PLAYERS		4
# define T_F				"fonts/towerruins.ttf"
# define B_F				"fonts/OpenSans-Regular.ttf"
# define BB_F				"fonts/OpenSans-Bold.ttf"
# define P1_C				0xFF0000
# define P1_C_L				0xe54949
# define P2_C				0x00FF00
# define P2_C_L				0x40d140
# define P3_C				0x0000FF
# define P3_C_L				0x3535dd
# define P4_C				0xFFFF00
# define P4_C_L				0xdbdb41
# define EM_C				0xFFFFFF
# define EM_C_L				0xaeb1b7
# define RED_LIGHT			"textures/light_red.png"
# define GREEN_LIGHT		"textures/light_green.png"
# define BLUE_LIGHT			"textures/light_blue.png"
# define YELLOW_LIGHT		"textures/light_yellow.png"
# define GREY_LIGHT			"textures/light_grey.png"
# define RED_LIGHT_L		"textures/light_red_l.png"
# define GREEN_LIGHT_L		"textures/light_green_l.png"
# define BLUE_LIGHT_L		"textures/light_blue_l.png"
# define YELLOW_LIGHT_L		"textures/light_yellow_l.png"
# define GREY_LIGHT_L		"textures/light_grey_l.png"
# define WARRIOR			"textures/warrior_sprites.png"
# define WARRIOR_D			"textures/warrior_death_sprites.png"
# define MAGE				"textures/mage_sprites.png"
# define MAGE_D				"textures/mage_death_sprites.png"
# define ORK				"textures/ork_sprites.png"
# define ORK_D				"textures/ork_death_sprites.png"
# define WOLF				"textures/wolf_sprites.png"
# define WOLF_D				"textures/wolf_death_sprites.png"
# define BG_IMG				"textures/bg.png"
# define BOR_BG_IMG			"textures/boring_bg.png"
# define WIN_BG				"textures/win_bg.png"
# define WHOOPIE			"textures/pikul.png"
# define ALIVE				1
# define DYING				2
# define DEAD				0
# define CARRET				1
# define LIGHT_UP			2
# define NOTHING			0
# define C0_1				(int[]){150, 300, 30, 255, 0, 0}
# define C0_2				(int[]){151, 301, 30, 0, 0, 0}
# define C1_1				(int[]){1550, 300, 30, 0, 255, 0}
# define C1_2				(int[]){1551, 301, 30, 0, 0, 0}
# define C2_1				(int[]){150, 1020, 30, 0, 0, 255}
# define C2_2				(int[]){151, 1021, 30, 0, 0, 0}
# define C3_1				(int[]){1550, 1020, 30, 255, 255, 0}
# define C3_2				(int[]){1551, 1021, 30, 0, 0, 0}

/*
**	STRUCTS
*/

typedef struct			s_render
{
	int					i;
	int					j;
	int					k;
	double				pi;
	double				pj;
	double				ppi;
	double				ppj;
}						t_render;

typedef struct			s_sprite
{
	SDL_Surface			*spr;
	SDL_Rect			rect[4];
	SDL_Surface			*spr_d;
	SDL_Rect			rect_d[6];
}						t_sprite;

typedef struct			s_audio
{
	Mix_Chunk			*fight;
	Mix_Chunk			*victory;
	Mix_Chunk			*die_1;
	Mix_Chunk			*die_2;
	Mix_Chunk			*die_3;
	Mix_Chunk			*die_4;
	Mix_Chunk			*woopie;
	Mix_Music			*music;
}						t_audio;

typedef struct			s_sdl
{
	int					pause;
	int					quit;
	int					frame_4;
	int					frame_6;
	int					boring_mode;
	int					winner;
	int					whoopie;
	int					autoplay;
	int					th;
	int					tr;
	int					rend_speed;
	SDL_Window			*window;
	SDL_Surface			*screen;
	SDL_Surface			*bg;
	SDL_Surface			*bor_bg;
	SDL_Surface			*text;
	SDL_Surface			*red;
	SDL_Surface			*green;
	SDL_Surface			*blue;
	SDL_Surface			*yellow;
	SDL_Surface			*grey;
	SDL_Surface			*red_l;
	SDL_Surface			*green_l;
	SDL_Surface			*blue_l;
	SDL_Surface			*yellow_l;
	SDL_Surface			*grey_l;
	t_sprite			wolf;
	t_sprite			warrior;
	t_sprite			mage;
	t_sprite			ork;
	t_sprite			win_bg;
	t_sprite			pikul;
	t_audio				audio;
	TTF_Font			*font;
	TTF_Font			*font_p;
	TTF_Font			*font_m1;
	TTF_Font			*font_m2;
	SDL_Event			event;
	t_map				map;
}						t_sdl;

/*
**	PROTOTYPES
*/

/*
**	main.c
*/

void					main_render(t_sdl *sdl);
void					main_loop(t_sdl *sdl);
/*
**	main_utils.c
*/

void					main_loop_events(t_sdl *sdl);
void					error(char *line);
void					frame_inc(t_sdl *sdl);
int						thread_func(void *data);

/*
**	sdl_init.c
*/

int						init_sdl(t_sdl *sdl);
int						init_window(t_sdl *sdl);
int						init_renderer(t_sdl *sdl);

/*
**	sdl_utils.c
*/

void					put_info(t_sdl *sdl, char *font, char *text, int k[6]);
void					put_player_info(t_sdl *sdl, char *text, int k[6]);
void					put_map_info(t_sdl *sdl, int fo, char *text, int k[6]);

/*
**	render.c
*/

void					render_map(t_sdl *sdl);
void					put_image(t_sdl *sdl, SDL_Surface *surface, int c[4]);

/*
**	intro.c
*/

void					get_ready_to_rumble(t_sdl *sdl);

/*
**	loading.c
*/

void					load_images(t_sdl *sdl);
void					put_players(t_sdl *sdl);

/*
**	death_check.c
*/

void					check_if_bots_are_dying(t_sdl *sdl);

/*
**	put_frame.c
*/

void					put_6_frame(t_sdl *sdl, SDL_Rect r, t_sprite sprite);
void					put_4_frame(t_sdl *sdl, SDL_Rect r, t_sprite sprite);
void					load_bg(t_sdl *sdl);

/*
**	boring_render.c
*/

void					render_boring_map(t_sdl *sdl);
void					load_boring_bg(t_sdl *sdl);

/*
**	print_info.c
*/

void					print_boring_stuff(t_sdl *sdl);

/*
**	winner_render.c
*/

void					winner_render(t_sdl *sdl);

/*
**	sound_loader.c
*/

void					load_music(t_sdl *sdl);
void					play_random_kill(t_sdl *sdl);
void					pikul(t_sdl *sdl);

/*
**  utils_render_1.c
*/

void					loading_put_bots_util(t_sdl *sdl);

/*
** nashi functions, podelim pri razvode!
*/

void					parse(int argc, char **argv, t_map *map);
void					put_bots(t_map *map, t_bot *bot);
void					add_carry(t_map *map, t_carry *carry);
void					print_field(unsigned char *map, char *cell_id);
void					print_bot(t_bot *bot);
t_carry					*create_carry(unsigned char id,
						int *reg, int live, char c);
void					delete_carry(t_carry **carry);
short					convert_to_short(unsigned char *map, int pos);
int						convert_to_int(unsigned char *map, int pos);
t_bot					*find_bot(t_bot *bot, int id);
int						get_arg(unsigned char arg, int id);
void					convert_to_char4(unsigned char *dst, int src);
t_bot					*find_bot(t_bot *bot, int id);
int						get_arg(unsigned char codage, int id);
void					bit_function(t_map *map,
						t_carry *carry, char operation);
int						carry_alive(t_map *map);
void					write_bytes(unsigned char *map,
						int pos, int src, short len);
void					write_id(char *map,
						int pos, unsigned char id, short len);
void					write_buf(unsigned char *map,
						int pos, unsigned char *dst, short len);
int						valid_treg(unsigned char byte);
int						valid_fun_id(int id);
int						valid_codage(int id, unsigned char codage);
int						shift(unsigned char codage, char label, int fun_id);
void					main_cycle(t_sdl *sdl);
void					f_live(t_map *map, t_carry *carry);
void					f_ld(t_map *map, t_carry *carry);
void					f_st(t_map *map, t_carry *carry);
void					f_add(t_map *map, t_carry *carry);
void					f_sub(t_map *map, t_carry *carry);
void					f_and(t_map *map, t_carry *carry);
void					f_or(t_map *map, t_carry *carry);
void					f_xor(t_map *map, t_carry *carry);
void					f_zjmp(t_map *map, t_carry *carry);
void					f_ldi(t_map *map, t_carry *carry);
void					f_sti(t_map *map, t_carry *carry);
void					f_fork(t_map *map, t_carry *carry);
void					f_lld(t_map *map, t_carry *carry);
void					f_lldi(t_map *map, t_carry *carry);
void					f_lfork(t_map *map, t_carry *carry);
void					f_aff(t_map *map, t_carry *carry);
void					print_info(t_map *map);
void					print_carry(t_carry *carry);
int						get_value(int arg, unsigned char *buf);
void					init_struct_for_mtupikov(t_map *map, t_carry *tmp);
int						convert_to_reg(unsigned char *map, int pos);
int						valid_n(int *map, int id);
void					flag_n(t_bot *bot, int *map);
t_bot					*get_bot(int nb, t_bot *bot);
t_bot					*create_bot(int fd, char *filename, int n);
void					add_bot(t_bot **begin, t_bot *bot);
int						check_magic(unsigned char *skip);
void					ft_intcpy(int *dst, int *src, int len);
void					init_carry_fun_id(t_carry *carry, t_map *map, t_fun *f);
void					make_job(t_carry *carry,
						t_map *map, t_fun *f, int *flag);
void					init_sdl_struct(t_sdl *sdl);
int						check_time(t_bot *bot);
void					init_vis(t_sdl *sdl);
void					dump_memory(t_map *map);
void					introduce_champs(t_bot *bot);
t_bot					*print_winner(t_bot *begin);
void					print_error(int err_code, int i, char *file);
void					vis_winner(t_sdl *sdl, t_bot *bot);
# define MV(pos, i) ((pos + i) % 4096 + (4096 * (i + pos < 0))) % 4096

# define C_DIR(c, i) (get_arg(c, i) == T_DIR)
# define C_REG(c, i) (get_arg(c, i) == T_REG)
# define C_IND(c, i) (get_arg(c, i) == T_IND)
# define NE_NULL(c, i) (get_arg(c, 0) != 0)

# define LD(c) ((C_DIR(c, 0) || C_IND(c, 0)) && C_REG(c, 1))
# define ST(c) (C_REG(c, 0) && (C_REG(c, 1) || C_IND(c, 1)))
# define ADD(c) (C_REG(c, 0) && C_REG(c, 1) && C_REG(c, 2))
# define SUB(c) (C_REG(c, 0) && C_REG(c, 1) && C_REG(c, 2))
# define AND(c) (NE_NULL(c, 0) && NE_NULL(c, 1) && C_REG(c, 2))
# define OR(c)  (NE_NULL(c, 0) && NE_NULL(c, 1) && C_REG(c, 2))
# define XOR(c) (NE_NULL(c, 0) && NE_NULL(c, 1) && C_REG(c, 2))
# define LDI(c) (NE_NULL(c, 0) && (C_REG(c, 1) || C_DIR(c, 1)) && C_REG(c, 2))
# define STI(c) (C_REG(c, 0) && NE_NULL(c, 1) && (C_REG(c, 2) || C_DIR(c, 2)))
# define LLD(c) ((C_DIR(c, 0) || C_IND(c, 0)) && C_REG(c, 1))
# define LLDI(c) (NE_NULL(c, 0) && (C_REG(c, 1) || C_DIR(c, 1)) && C_REG(c, 2))
# define AFF(c) (C_REG(c, 0))

# define OUTPUT_MODE(flag) (flag == 'd' || flag == 'n' || flag == 'v')

#endif
