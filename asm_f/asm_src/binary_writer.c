/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_binary_writer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:20:27 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 14:20:31 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm_inc/asm.h"

char	*asm_move_file(int f, char *file)
{
	if (f == 1 || f == 9 || f == 12 || f == 14)
		file = file + 4;
	else if (f == 2 || f == 3 || f == 7)
		file = file + 2;
	else if (f == 15)
		file = file + 5;
	else
		file = file + 3;
	while (*file && (*file == ' ' || *file == '\t'))
		file++;
	return (file);
}

int		asm_separator_move(char **file)
{
	while (**file && **file != SEPARATOR_CHAR && **file != '\n')
		(*file)++;
	if (**file == '\n')
		return (1);
	(*file)++;
	while (**file && (**file == ' ' || **file == '\t'))
		(*file)++;
	return (1);
}

int		asm_call_util_2(int f, int fd, t_label *label, char **file)
{
	if ((f == 6 || f == 7 || f == 8) && asm_opcode(fd, 3, 0, *file)
		&& ((asm_write_reg(fd, file) || asm_write_dir(fd, 4, label, file) ||
		asm_write_ind(fd, label, file)) &&
		((asm_write_reg(fd, file) || asm_write_dir(fd, 4, label, file) ||
		asm_write_ind(fd, label, file)))))
		return (asm_write_reg(fd, file));
	else if (f == 9 || f == 12 || f == 15)
		return (asm_write_dir(fd, 2, label, file));
	else if ((f == 10 || f == 14) && asm_opcode(fd, 3, 0, *file) &&
		(((asm_write_reg(fd, file) || asm_write_dir(fd, 2, label, file) ||
		asm_write_ind(fd, label, file)) &&
		(asm_write_reg(fd, file) || asm_write_dir(fd, 2, label, file)))))
		return (asm_write_reg(fd, file));
	else if (f == 11 && asm_opcode(fd, 3, 0, *file) &&
		((asm_write_reg(fd, file) && (asm_write_reg(fd, file) ||
		asm_write_dir(fd, 2, label, file) || asm_write_ind(fd, label, file)) &&
		(asm_write_reg(fd, file) || asm_write_dir(fd, 2, label, file)))))
		return (1);
	else if (f == 16 && write(fd, "@", 1) && ++g_temp)
		return (asm_write_reg(fd, file));
	return (1);
}

int		asm_call_util(int f, int fd, t_label *label, char **file)
{
	*file = asm_move_file(f, *file);
	write(fd, &f, 1);
	if (f == 1)
		return (asm_write_dir(fd, 4, label, file));
	else if ((f == 2 || f == 13) && asm_opcode(fd, 2, 0, *file) &&
		((asm_write_dir(fd, 4, label, file) || asm_write_ind(fd, label, file))))
		return (asm_write_reg(fd, file));
	else if (f == 3 && asm_opcode(fd, 2, 0, *file) && asm_write_reg(fd, file)
		&& (asm_write_reg(fd, file) || asm_write_ind(fd, label, file)))
		return (1);
	else if ((f == 4 || f == 5) && write(fd, "T", 1) && ++g_temp &&
		asm_write_reg(fd, file) && asm_write_reg(fd, file) &&
		asm_write_reg(fd, file))
		return (1);
	return (asm_call_util_2(f, fd, label, file));
}

int		asm_binary_creator(int fd, t_label *label, char *file)
{
	int f;

	while (*file)
	{
		f = asm_instruct_name(file);
		if (f)
			g_temp++;
		asm_call_util(f, fd, label, &file);
		while (*file && *file != '\n')
			file++;
		file++;
		g_pos = g_pos + g_temp;
		g_temp = 0;
	}
	return (1);
}
