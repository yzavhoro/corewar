/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:21:24 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 14:21:27 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm_inc/asm.h"

/*
** Check if the SEPARATOR_CHAR is correct
*/

int		asm_check_virgule(char **line)
{
	while (**line == '\t' || **line == ' ')
		(*line)++;
	if (**line != SEPARATOR_CHAR)
		return (asm_error(8));
	(*line)++;
	while (**line == '\t' || **line == ' ')
		(*line)++;
	return (1);
}

/*
** Check if DIRECT_CHAR is correct
*/

int		asm_check_dir(char **line, int op, int check)
{
	if (**line == DIRECT_CHAR)
	{
		if (op > 8 && op != 13)
			g_pos = g_pos + 2;
		else
			g_pos = g_pos + 4;
		(*line)++;
		if (**line != LABEL_CHAR && !(**line >= '0' && **line <= '9') &&
		**line != '-' && **line != '+')
			asm_error_sec(15);
		if (**line == LABEL_CHAR)
			(*line)++;
		else if (**line == '+' || **line == '-')
			(*line)++;
		while (**line && ft_strchr(LABEL_CHARS, **line))
			(*line)++;
		while (**line == ' ' || **line == '\t')
			(*line)++;
		if (check == 1)
			return (asm_check_virgule(line));
		return (1);
	}
	return (0);
}

/*
** Check if REG_NUM is correct
*/

int		asm_check_reg(char **line, int check)
{
	int r;

	if (**line == 'r')
	{
		(*line)++;
		r = (int)ft_atoi(*line);
		if (r > REG_NUMBER || r <= 0)
			return (asm_error(9));
		(*line)++;
		if (r > 9)
			(*line)++;
		if (r > 99)
			(*line)++;
		g_pos++;
		if (check == 1)
			return (asm_check_virgule(line));
		return (1);
	}
	return (0);
}

/*
** Check if the indirect is correct
*/

int		asm_check_ind(char **line, int check)
{
	if (**line == LABEL_CHAR)
	{
		(*line)++;
		while (**line && ft_strchr(LABEL_CHARS, **line))
			(*line)++;
	}
	else if (((**line == '+' || **line == '-') && (*line)++) ||
	ft_isdigit(**line))
	{
		while (ft_isdigit(**line))
			(*line)++;
	}
	else
		return (0);
	if (**line != '\0' && **line != '\n'
		&& **line != SEPARATOR_CHAR && **line != ' ' && **line != '\t')
		return (asm_error(7));
	g_pos = g_pos + 2;
	if (check == 1)
		return (asm_check_virgule(line));
	return (1);
}

/*
** Increment line according to the instruction passed
*/

int		check_valid_line(char *line)
{
	int	f;

	f = asm_instruct_name(line);
	if (f)
		g_pos++;
	if (f == 1 || f == 9 || f == 12 || f == 14)
		line = line + 4;
	else if (f == 2 || f == 3 || f == 7)
		line = line + 2;
	else if (f == 15)
		line = line + 5;
	else
		line = line + 3;
	if (f != 1 && f != 9 && f != 12 & f != 15)
		g_pos++;
	asm_check_arg(&line, f);
	while (*line && *line != '\n' && *line != COMMENT_CHAR && *line != ';')
		if (*line && *line != ' ' && *line != '\t' && *line != '\n')
			return (asm_error(12));
		else
			line++;
	return (1);
}
