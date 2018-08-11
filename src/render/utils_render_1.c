/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:34:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/06 14:34:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	loading_put_bots_util(t_sdl *sdl)
{
	t_bot *bot;

	bot = get_bot(2, sdl->map.bots);
	if (bot && get_bot(2, sdl->map.bots)->is_alive == ALIVE)
	{
		put_4_frame(sdl, (SDL_Rect){200, 790, 100, 100}, sdl->mage);
		put_player_info(sdl, (char *)bot->name, C2_1);
		put_player_info(sdl, (char *)bot->name, C2_2);
	}
	bot = get_bot(3, sdl->map.bots);
	if (bot && get_bot(3, sdl->map.bots)->is_alive == ALIVE)
	{
		put_4_frame(sdl, (SDL_Rect){1630, 790, 100, 100}, sdl->warrior);
		put_player_info(sdl, (char *)bot->name, C3_1);
		put_player_info(sdl, (char *)bot->name, C3_2);
	}
}
