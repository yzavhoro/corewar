/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:28:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/07 17:28:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	pikul(t_sdl *sdl)
{
	static int d = 0;

	if (d == 0)
		Mix_PlayChannel(-1, sdl->audio.woopie, 0);
	put_image(sdl, sdl->pikul.spr, (int[]){1730, 900, 200, 200});
	if (d == 7)
	{
		sdl->whoopie = 0;
		d = 0;
	}
	else
		d++;
}

void	winner_render(t_sdl *sdl)
{
	static int	s = 0;
	char		*w_t;
	t_sprite	spr;

	put_image(sdl, sdl->win_bg.spr, (int[]){0, 0, 1920, 1080});
	sdl->frame_4 = 0;
	if (sdl->winner == 1)
		spr = sdl->ork;
	else if (sdl->winner == 2)
		spr = sdl->wolf;
	else if (sdl->winner == 3)
		spr = sdl->mage;
	else
		spr = sdl->warrior;
	put_4_frame(sdl, (SDL_Rect){650, 100, 500, 800}, spr);
	w_t = ft_strjoin((char *)get_bot(sdl->winner - 1,
	sdl->map.bots)->name, " has won!");
	put_info(sdl, T_F, w_t, (int[]){650, 950, 40, 0xFF, 0xFF, 0xFF});
	put_info(sdl, T_F, "Press any key to exit.",
	(int[]){650, 1000, 40, 0xFF, 0xFF, 0xFF});
	ft_strdel(&w_t);
	if (!s)
		Mix_PlayChannel(-1, sdl->audio.victory, 0);
	s = 1;
}
