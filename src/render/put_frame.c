/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:25:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/06 16:25:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	put_4_frame(t_sdl *sdl, SDL_Rect r, t_sprite sprite)
{
	SDL_Rect	*t;
	SDL_Surface	*s;

	t = &sprite.rect[sdl->frame_4];
	s = sprite.spr;
	SDL_BlitScaled(s, t, sdl->screen, &r);
}

void	put_6_frame(t_sdl *sdl, SDL_Rect r, t_sprite sprite)
{
	SDL_Rect	*t;
	SDL_Surface	*s;

	t = &sprite.rect_d[sdl->frame_6];
	s = sprite.spr_d;
	SDL_BlitScaled(s, t, sdl->screen, &r);
}

void	load_bg(t_sdl *sdl)
{
	SDL_BlitScaled(sdl->bg, NULL, sdl->screen, NULL);
}
