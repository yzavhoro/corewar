/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:29:34 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 14:29:35 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

/*
** INCLUDES
*/

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

/*
** DEFINES
*/

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3
# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define T_REG					1
# define T_DIR					2
# define T_IND					2
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define REG_NUMBER				16

int						g_line;
int						g_pos;
int						g_temp;

/*
** STRUCTS
*/

typedef struct			s_label
{
	char				*name;
	unsigned int		pos;
	struct s_label		*next;
}						t_label;

typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

/*
** PROTOTYPES
*/

/*
**	error.c
*/

int						asm_error(int error);
int						asm_error_sec(int error);

/*
**	init.c
*/

t_header				*asm_header_init(void);
t_label					*asm_label_init(t_label *label, char *line);

/*
**	free.c
*/

int						asm_ready_header(t_header *head, char *line);
int						asm_free_label(t_label *label);
char					*asm_free_join(char *line, char *file);
char					*asm_realloc(char *line, char *file, int i);

/*
**	main.c
*/

void					asm_init_global(void);
int						asm_argc_check(int argc);

/*
** parse_instruct.c
*/

int						asm_instruct_name_sec(char *line);
int						asm_instruct_name(char *line);
int						asm_move_my_i(int i, char *file);
int						asm_calculate_i(char *file, t_label *label);

/*
** check_arg.c
*/

int						asm_check_arg(char **line, int op);
int						asm_check_arg_sec(char **line, int op);

/*
** parsing.c
*/

int						asm_check_champ(char *champ);
char					*asm_put_line_in_file(char *line, int i, char *file);
t_label					*asm_parse_line(int fd, char **file);
void					asm_bonus_champ(t_header *head);
int						asm_parsing(char *champion, t_header *head);

/*
** copy_header.c
*/

int						asm_header_pass(char *line, int name, int com,
						int check);
int						asm_header_pass_end(char *line, int i);
t_header				*asm_copy_header(char *line, t_header *head, int check);
int						asm_copy_name_comment(char *line, t_header *head,
						int name, int com);
int						asm_handler_name_comment(int fd, t_header *head);

/*
** check_instruct.c
*/

int						asm_check_virgule(char **line);
int						asm_check_dir(char **line, int op, int check);
int						asm_check_reg(char **line, int check);
int						asm_check_ind(char **line, int check);
int						check_valid_line(char *line);

/*
** writer.c
*/

int						cw_invert_endian2(int x);
int						cw_invert_endian(int x);
int						asm_header_creator(int fd, t_header *header);
char					*asm_morph_cor(char *champ);
int						asm_reader(t_label *label, t_header *header,
						char *champ, char *file);

/*
** binary_writer.c
*/

int						asm_move_g_file(int f);
int						asm_separator_move(char **file);
int						asm_call_util(int f, int fd, t_label *label,
						char **file);
int						asm_binary_creator(int fd, t_label *label, char *file);

/*
** check_label.c
*/

int						asm_match_label(t_label *label, char *str);
int						asm_check_label_exist(t_label *label, char *str);
int						asm_check_label(char *str);
int						asm_check_double_label(t_label *label);

/*
** write_octal.c
*/

int						asm_opcode(int fd, int arg, int i, char *file);
int						asm_write_dir(int fd, int size, t_label *label,
						char **file);
int						asm_write_ind(int fd, t_label *label, char **file);
int						asm_write_reg(int fd, char **file);

#endif
