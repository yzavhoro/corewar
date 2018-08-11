/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 14:08:11 by mtupikov          #+#    #+#             */
/*   Updated: 2018/07/28 14:08:13 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	put_text_to_font(t_sdl *sdl, TTF_Font *font, char *line, int c[3])
{
	sdl->text = TTF_RenderText_Solid(font, line,
	(SDL_Color){c[0], c[1], c[2], 255});
}

void	put_info(t_sdl *sdl, char *font, char *text, int k[6])
{
	if (!(sdl->font = TTF_OpenFont(font, k[2])))
		error((char *)TTF_GetError());
	put_text_to_font(sdl, sdl->font, text, (int[]){k[3], k[4], k[5]});
	SDL_BlitSurface(sdl->text, NULL, sdl->screen,
					&(SDL_Rect){k[0], k[1], 20, 20});
	TTF_CloseFont(sdl->font);
	SDL_FreeSurface(sdl->text);
}

void	put_player_info(t_sdl *sdl, char *text, int k[6])
{
	put_text_to_font(sdl, sdl->font_p, text, (int[]){k[3], k[4], k[5]});
	SDL_BlitSurface(sdl->text, NULL, sdl->screen,
					&(SDL_Rect){k[0], k[1], 20, 20});
	SDL_FreeSurface(sdl->text);
}

void	put_map_info(t_sdl *sdl, int font, char *text, int k[6])
{
	TTF_Font *f;

	if (font == 1)
		f = sdl->font_m1;
	else
		f = sdl->font_m2;
	put_text_to_font(sdl, f, text, (int[]){k[3], k[4], k[5]});
	SDL_BlitSurface(sdl->text, NULL, sdl->screen,
	&(SDL_Rect){k[0], k[1], 20, 20});
	SDL_FreeSurface(sdl->text);
}
