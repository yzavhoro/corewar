/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:34:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/06 14:34:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	put_players(t_sdl *sdl)
{
	t_bot *bot;

	bot = get_bot(0, sdl->map.bots);
	if (bot && get_bot(0, sdl->map.bots)->is_alive == ALIVE)
	{
		put_4_frame(sdl, (SDL_Rect){200, 80, 100, 100}, sdl->ork);
		put_player_info(sdl, (char *)bot->name, C0_1);
		put_player_info(sdl, (char *)bot->name, C0_2);
	}
	bot = get_bot(1, sdl->map.bots);
	if (bot && get_bot(1, sdl->map.bots)->is_alive == ALIVE)
	{
		put_4_frame(sdl, (SDL_Rect){1630, 70, 100, 100}, sdl->wolf);
		put_player_info(sdl, (char *)bot->name, C1_1);
		put_player_info(sdl, (char *)bot->name, C1_2);
	}
	loading_put_bots_util(sdl);
	check_if_bots_are_dying(sdl);
}

void	set_sprite(t_sprite *sprite)
{
	sprite->rect[0].x = 0;
	sprite->rect[0].y = 0;
	sprite->rect[0].h = 500;
	sprite->rect[0].w = 500;
	sprite->rect[1].x = 0;
	sprite->rect[1].y = 500;
	sprite->rect[1].h = 500;
	sprite->rect[1].w = 500;
	sprite->rect[2].x = 500;
	sprite->rect[2].y = 0;
	sprite->rect[2].h = 500;
	sprite->rect[2].w = 500;
	sprite->rect[3].x = 500;
	sprite->rect[3].y = 500;
	sprite->rect[3].h = 500;
	sprite->rect[3].w = 500;
}

void	set_sprite_d(t_sprite *sprite)
{
	sprite->rect_d[0].x = 0;
	sprite->rect_d[0].y = 0;
	sprite->rect_d[0].h = 500;
	sprite->rect_d[0].w = 500;
	sprite->rect_d[1].x = 500;
	sprite->rect_d[1].y = 0;
	sprite->rect_d[1].h = 500;
	sprite->rect_d[1].w = 500;
	sprite->rect_d[2].x = 1000;
	sprite->rect_d[2].y = 0;
	sprite->rect_d[2].h = 500;
	sprite->rect_d[2].w = 500;
	sprite->rect_d[3].x = 1500;
	sprite->rect_d[3].y = 0;
	sprite->rect_d[3].h = 500;
	sprite->rect_d[3].w = 500;
	sprite->rect_d[4].x = 0;
	sprite->rect_d[4].y = 500;
	sprite->rect_d[4].h = 500;
	sprite->rect_d[4].w = 500;
	sprite->rect_d[5].x = 500;
	sprite->rect_d[5].y = 500;
	sprite->rect_d[5].h = 500;
	sprite->rect_d[5].w = 500;
}

void	load_spites(t_sdl *sdl)
{
	sdl->red = IMG_Load(RED_LIGHT);
	sdl->green = IMG_Load(GREEN_LIGHT);
	sdl->blue = IMG_Load(BLUE_LIGHT);
	sdl->yellow = IMG_Load(YELLOW_LIGHT);
	sdl->grey = IMG_Load(GREY_LIGHT);
	sdl->red_l = IMG_Load(RED_LIGHT_L);
	sdl->green_l = IMG_Load(GREEN_LIGHT_L);
	sdl->blue_l = IMG_Load(BLUE_LIGHT_L);
	sdl->yellow_l = IMG_Load(YELLOW_LIGHT_L);
	sdl->grey_l = IMG_Load(GREY_LIGHT_L);
	sdl->warrior.spr = IMG_Load(WARRIOR);
	sdl->warrior.spr_d = IMG_Load(WARRIOR_D);
	sdl->ork.spr = IMG_Load(ORK);
	sdl->ork.spr_d = IMG_Load(ORK_D);
	sdl->mage.spr = IMG_Load(MAGE);
	sdl->mage.spr_d = IMG_Load(MAGE_D);
	sdl->wolf.spr = IMG_Load(WOLF);
	sdl->wolf.spr_d = IMG_Load(WOLF_D);
	sdl->win_bg.spr = IMG_Load(WIN_BG);
	sdl->pikul.spr = IMG_Load(WHOOPIE);
	sdl->bg = IMG_Load(BG_IMG);
	sdl->font_p = TTF_OpenFont(T_F, 40);
	sdl->font_m1 = TTF_OpenFont(B_F, 15);
	sdl->font_m2 = TTF_OpenFont(BB_F, 15);
	sdl->bor_bg = IMG_Load(BOR_BG_IMG);
}

void	load_images(t_sdl *sdl)
{
	load_spites(sdl);
	set_sprite(&sdl->warrior);
	set_sprite_d(&sdl->warrior);
	set_sprite(&sdl->mage);
	set_sprite_d(&sdl->mage);
	set_sprite(&sdl->wolf);
	set_sprite_d(&sdl->wolf);
	set_sprite(&sdl->ork);
	set_sprite_d(&sdl->ork);
}
