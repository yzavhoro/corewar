/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 17:52:04 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/07/28 15:35:17 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	introduce_champs(t_bot *bot)
{
	ft_printf("Introducing contestants...\n");
	while (bot)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			-bot->id, bot->size_code, bot->name, bot->comment);
		bot = bot->next;
	}
}

t_bot	*print_winner(t_bot *bot)
{
	t_bot *winner;

	winner = bot;
	while (bot)
	{
		if (bot->live > winner->live)
			winner = bot;
		bot = bot->next;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", -winner->id, winner->name);
	return (winner);
}

void	print_error(int err_code, int i, char *file)
{
	if (err_code == 0)
		ft_printf("Usage: ./corewar [-d N | -v] [-a] [-n N] <champion1.cor> \
<...>\n    -a        : Prints output from \"aff\" (Default is to \
hide it)\n    -dump N   : Dumps memory after N cycles then \
exits\n    -n N      : Sets the number of the next \
player\n    -v N      : Visualisation output mode\n");
	if (err_code == 1)
		ft_printf("Error: File %s has too large a code (%d bytes > %d bytes)\n",
			file, i, CHAMP_MAX_SIZE);
	else if (err_code == 2)
		ft_printf("Error: File %s is invalid\n", file);
	else if (err_code == 3)
		ft_putendl("Error: too many champions");
	else if (err_code == 4)
		ft_printf("Error: Flag %s is invalid\n", file);
	else if (err_code == 5)
		ft_putendl("Error: Champions are missing");
	else if (err_code == 6)
		ft_putendl("Error: [-n] [1-4] [champ]");
	exit(0);
}
