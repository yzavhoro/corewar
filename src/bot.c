/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:49:58 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/27 16:45:09 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void			init_live(t_bot *bot, int n)
{
	bot->live = 0;
	bot->lives = 0;
	bot->is_alive = ALIVE;
	bot->id = n;
}

t_bot				*create_bot(int fd, char *filename, int n)
{
	t_bot			*bot;
	unsigned char	skip[SKIP_SIZE];
	char			*cor;

	cor = ft_strstr(filename, ".cor");
	if (!cor || *(cor + 4) ||
			(read(fd, skip, SKIP_SIZE) == -1) || !check_magic(skip))
		print_error(2, 0, filename);
	if (n > 4)
		print_error(3, 0, NULL);
	bot = (t_bot*)malloc(sizeof(t_bot));
	read(fd, bot->name, PROG_NAME_LENGTH);
	read(fd, skip, SKIP_SIZE);
	read(fd, skip, EXECUTABLE_CODE_SIZE);
	bot->size_code = convert_to_int(skip, 0);
	bot->size_code > CHAMP_MAX_SIZE ?
		print_error(1, bot->size_code, filename) : NULL;
	read(fd, bot->comment, COMMENT_LENGTH);
	read(fd, skip, SKIP_SIZE);
	bot->code = (unsigned char*)malloc(sizeof(unsigned char) * bot->size_code);
	read(fd, bot->code, bot->size_code);
	init_live(bot, n);
	bot->next = NULL;
	close(fd);
	return (bot);
}

t_bot				*get_bot(int nb, t_bot *bot)
{
	while (bot && nb--)
		bot = bot->next;
	return (bot);
}

t_bot				*find_bot(t_bot *bot, int id)
{
	while (bot)
	{
		if (bot->id == id)
			return (bot);
		bot = bot->next;
	}
	return (NULL);
}

void				add_bot(t_bot **begin, t_bot *bot)
{
	t_bot	*cur;

	cur = *begin;
	if (*begin)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = bot;
	}
	else
		*begin = bot;
}
