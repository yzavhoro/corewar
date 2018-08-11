/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:21:04 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 14:21:06 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm_inc/asm.h"

/*
** Return 1 if the header is complete
*/

int			asm_ready_header(t_header *head, char *line)
{
	if (head->comment[0] && head->prog_name[0])
	{
		if (ft_strrchr(line, '"') != ft_strchr(line, '"'))
		{
			free(line);
			return (1);
		}
		return (asm_error(13));
	}
	return (0);
}

int			asm_free_label(t_label *label)
{
	t_label	*nxt;

	nxt = label->next;
	while (nxt)
	{
		label->next = NULL;
		free(label->name);
		free(label);
		label = nxt;
		nxt = label->next;
	}
	free(label->name);
	free(label);
	return (1);
}

/*
** Function that realloc to retrieve the entire .s file
*/

char		*asm_realloc(char *line, char *file, int i)
{
	int		len;
	char	*tmp;
	char	*sub;

	if (!ft_strcmp(line, "fork %:goboucle1"))
		i += 0;
	len = 0;
	tmp = NULL;
	sub = NULL;
	sub = ft_strsub(line, i, ft_strlen(line) - i);
	tmp = ft_memalloc(sizeof(char) * (ft_strlen(file) + ft_strlen(sub) + 2));
	tmp = ft_strcpy(tmp, file);
	tmp = ft_strcat(tmp, sub);
	free(file);
	free(sub);
	file = NULL;
	sub = NULL;
	while (tmp[len])
		len++;
	tmp[len] = '\n';
	tmp[len + 1] = '\0';
	file = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (file);
}

char		*asm_free_join(char *line, char *file)
{
	int		i;
	int		len;
	char	*sub;

	i = 0;
	if (line[i])
	{
		if (!(len = 0) && !file)
		{
			sub = ft_strsub(line, i, ft_strlen(line) - i);
			file = malloc(sizeof(char) * (ft_strlen(sub) + 1));
			file = ft_strcpy(file, sub);
			while (file[len])
				len++;
			file[len] = '\n';
			file[len + 1] = '\0';
			free(sub);
		}
		else
			file = asm_realloc(line, file, i);
	}
	return (file);
}
