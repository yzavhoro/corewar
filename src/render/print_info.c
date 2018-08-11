/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:39:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/07 16:39:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		print_player_name(t_sdl *sdl, int i, int pos_x)
{
	char	*temp_1;
	char	*temp_2;
	t_bot	*bot;

	bot = get_bot(i, sdl->map.bots);
	temp_2 = ft_itoa(bot->id);
	temp_1 = ft_strjoin("Player #", temp_2);
	ft_strdel(&temp_2);
	temp_2 = ft_strjoin(temp_1, ": ");
	ft_strdel(&temp_1);
	temp_1 = ft_strjoin(temp_2, (char *)bot->name);
	put_map_info(sdl, 1, temp_1, (int[]){1600, pos_x, 20, 255, 255, 255});
	ft_strdel(&temp_1);
	ft_strdel(&temp_2);
	temp_2 = ft_itoa(bot->live);
	temp_1 = ft_strjoin("Last live: ", temp_2);
	put_map_info(sdl, 1, temp_1, (int[]){1600, pos_x + 30, 20, 255, 255, 255});
	ft_strdel(&temp_1);
	ft_strdel(&temp_2);
}

void		boring_winner(t_sdl *sdl)
{
	char	*w_t;

	w_t = ft_strjoin((const char *)get_bot(sdl->winner - 1,
	sdl->map.bots)->name, " has won!");
	put_map_info(sdl, 1, w_t, (int[]){1600, 500, 20, 0xFF, 0xFF, 0xFF});
	put_map_info(sdl, 1, "Press any key to exit.",
	(int[]){1600, 550, 20, 0xFF, 0xFF, 0xFF});
	ft_strdel(&w_t);
}

void		print_players(t_sdl *sdl)
{
	int		i;
	int		k;
	t_bot	*bot;

	i = -1;
	k = 30;
	while (++i < MAX_PLAYERS)
	{
		bot = get_bot(i, sdl->map.bots);
		if (bot)
		{
			print_player_name(sdl, i, 30 + k);
			k += 60;
		}
	}
}

void		print_util(t_sdl *sdl, char *line, int num, int pos)
{
	char *temp_1;
	char *temp_2;

	temp_1 = ft_itoa(num);
	temp_2 = ft_strjoin(line, temp_1);
	put_map_info(sdl, 1, temp_2, (int[]){1600, pos, 20, 255, 255, 255});
	ft_strdel(&temp_1);
	ft_strdel(&temp_2);
}

void		print_boring_stuff(t_sdl *sdl)
{
	print_players(sdl);
	print_util(sdl, "Cycle: ", sdl->map.cycle, 830);
	print_util(sdl, "Processes: ", sdl->map.nbr_carries, 860);
	print_util(sdl, "CYCLE_TO_DIE: ", sdl->map.cycle_to_die, 890);
	print_util(sdl, "CYCLE_DELTA: ", CYCLE_DELTA, 920);
	print_util(sdl, "NBR_LIVE: ", NBR_LIVE, 950);
	print_util(sdl, "MAX_CHECKS: ", MAX_CHECKS, 980);
	if (sdl->winner > 0)
		boring_winner(sdl);
}
