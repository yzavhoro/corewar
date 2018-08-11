/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:20:49 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 14:20:51 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm_inc/asm.h"

/*
** Check that file ends with .s
*/

int			asm_check_champ(char *champ)
{
	int i;

	i = 0;
	while (champ[i])
		i++;
	if (i > 3 && champ[i - 1] == 's' && champ[i - 2] == '.')
		return (1);
	else
		return (asm_error(14));
}

/*
** Put valid line in file
*/

char		*asm_put_line_in_file(char *line, int i, char *file)
{
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] && line[i] != COMMENT_CHAR && line[i] != ';' &&
	check_valid_line(&line[i]))
		file = asm_free_join(&line[i], file);
	free(line);
	return (file);
}

/*
** Retrieve the name of the label, position in a chained list
*/

t_label		*asm_parse_line(int fd, char **file)
{
	t_label	*label;
	char	*line;
	int		i;

	label = NULL;
	line = NULL;
	while (!(i = 0) && get_next_line(fd, &line) > 0)
	{
		g_line++;
		while (line[i] == '\t' || line[i] == ' ')
			i++;
		if (line[i] && line[i] != COMMENT_CHAR && line[i] != ';' &&
		asm_check_label(line) >= 1)
		{
			label = asm_label_init(label, line);
			while (line[i] != LABEL_CHAR)
				i++;
			i++;
		}
		*file = asm_put_line_in_file(line, i, *file);
	}
	free(line);
	return (label);
}

int			asm_parsing(char *champion, t_header *head)
{
	int			fd;
	char		*file;
	t_label		*label;

	file = NULL;
	asm_check_champ(champion);
	if ((fd = open(champion, O_RDONLY, 0555)) == -1)
		return (-1);
	asm_handler_name_comment(fd, head);
	label = asm_parse_line(fd, &file);
	asm_check_double_label(label);
	if (asm_check_label_exist(label, file) == 0)
		return (asm_error(12));
	asm_reader(label, head, champion, file);
	if (file && file[0])
		free(file);
	if (label)
		asm_free_label(label);
	return (0);
}
