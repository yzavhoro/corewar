/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:23:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/06 16:23:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	check_d_ork(t_sdl *sdl)
{
	static int	d = 0;
	t_bot		*bot;

	bot = sdl->map.bots;
	if (bot && bot->is_alive == DYING)
	{
		if (d == 0)
			play_random_kill(sdl);
		if (d >= 5)
		{
			bot->is_alive = DEAD;
			d = 0;
		}
		put_6_frame(sdl, (SDL_Rect){200, 80, 100, 100}, sdl->ork);
		put_info(sdl, T_F, (char *)bot->name, C0_1);
		put_info(sdl, T_F, (char *)bot->name, C0_2);
		d++;
	}
}

void	check_d_wolf(t_sdl *sdl)
{
	static int	d = 0;
	t_bot		*bot;

	bot = get_bot(1, sdl->map.bots);
	if (bot && bot->is_alive == DYING)
	{
		if (d == 0)
			play_random_kill(sdl);
		if (d >= 5)
		{
			bot->is_alive = DEAD;
			d = 0;
		}
		put_6_frame(sdl, (SDL_Rect){1630, 70, 100, 100}, sdl->wolf);
		put_info(sdl, T_F, (char *)bot->name, C1_1);
		put_info(sdl, T_F, (char *)bot->name, C1_2);
		d++;
	}
}

void	check_d_mage(t_sdl *sdl)
{
	static int	d = 0;
	t_bot		*bot;

	bot = get_bot(2, sdl->map.bots);
	if (bot && bot->is_alive == DYING)
	{
		if (d == 0)
			play_random_kill(sdl);
		if (d >= 5)
		{
			bot->is_alive = DEAD;
			d = 0;
		}
		put_6_frame(sdl, (SDL_Rect){1630, 70, 100, 100}, sdl->wolf);
		put_info(sdl, T_F, (char *)bot->name, C2_1);
		put_info(sdl, T_F, (char *)bot->name, C2_2);
		d++;
	}
}

void	check_d_warrior(t_sdl *sdl)
{
	static int	d = 0;
	t_bot		*bot;

	bot = get_bot(3, sdl->map.bots);
	if (bot && bot->is_alive == DYING)
	{
		if (d == 0)
			play_random_kill(sdl);
		if (d >= 5)
		{
			bot->is_alive = DEAD;
			d = 0;
		}
		put_6_frame(sdl, (SDL_Rect){1630, 790, 100, 100}, sdl->warrior);
		put_info(sdl, T_F, (char *)bot->name, C3_1);
		put_info(sdl, T_F, (char *)bot->name, C3_2);
		d++;
	}
}

void	check_if_bots_are_dying(t_sdl *sdl)
{
	check_d_ork(sdl);
	check_d_mage(sdl);
	check_d_warrior(sdl);
	check_d_wolf(sdl);
}
