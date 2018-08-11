/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:21:57 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 14:21:58 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm_inc/asm.h"

/*
** Check if the label exists
*/

int		asm_match_label(t_label *label, char *str)
{
	int	i;

	i = 0;
	while (ft_strchr(LABEL_CHARS, str[i]))
		i++;
	while (label)
	{
		if (ft_strncmp(label->name, str, i) == 0)
		{
			if (!label->name[i])
				return (1);
		}
		label = label->next;
	}
	return (asm_error(10));
}

int		asm_check_label_exist(t_label *label, char *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != DIRECT_CHAR)
	{
		len++;
		if (str[len] == DIRECT_CHAR)
		{
			len++;
			if (str[len] == LABEL_CHAR)
			{
				len++;
				asm_match_label(label, &str[len]);
			}
		}
	}
	return (1);
}

/*
** Check if there is a label and if it and the label_char are well formatted
*/

int		asm_check_label(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] && ft_strchr(LABEL_CHARS, str[i]))
		i++;
	if (str[i] == LABEL_CHAR && i > 0)
	{
		i++;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '\n' || str[i] == '\0' || str[i] == COMMENT_CHAR)
			return (1);
		return (2);
	}
	else if (str[i] && str[i] != ' ' && str[i] != '\0' && str[i] != ';' &&
	str[i] != '\n' && str[i] != '\t' && str[i] != COMMENT_CHAR && str[i] != ',')
	{
		if (str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\0')
			return (asm_error(4));
		return (asm_error(3));
	}
	return (0);
}

/*
** Check if there is a duplicate in the labels
*/

int		asm_check_double_label(t_label *label)
{
	t_label *start;

	start = label;
	if (!label)
		return (1);
	label = label->next;
	while (label)
	{
		if (ft_strcmp(start->name, label->name) == 0)
			return (asm_error(9));
		label = label->next;
	}
	return (asm_check_double_label(start->next));
}
