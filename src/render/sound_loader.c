/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:48:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/09 11:48:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	play_random_kill(t_sdl *sdl)
{
	int k;

	k = 0 + arc4random() % 100;
	if (k < 20)
		Mix_PlayChannel(-1, sdl->audio.die_1, 0);
	else if (k >= 20 && k < 50)
		Mix_PlayChannel(-1, sdl->audio.die_2, 0);
	else if (k >= 50 && k < 70)
		Mix_PlayChannel(-1, sdl->audio.die_3, 0);
	else if (k >= 70)
		Mix_PlayChannel(-1, sdl->audio.die_4, 0);
	k = 0 + arc4random() % 100;
	if (k > 40 && k < 50)
		sdl->whoopie = 1;
}

void	load_music(t_sdl *sdl)
{
	sdl->audio.music = Mix_LoadMUS("media/music.wav");
	sdl->audio.fight = Mix_LoadWAV("media/fight.wav");
	sdl->audio.victory = Mix_LoadWAV("media/victory.wav");
	sdl->audio.die_1 = Mix_LoadWAV("media/die_1.wav");
	sdl->audio.die_2 = Mix_LoadWAV("media/die_2.wav");
	sdl->audio.die_3 = Mix_LoadWAV("media/die_3.wav");
	sdl->audio.die_4 = Mix_LoadWAV("media/die_4.wav");
	sdl->audio.woopie = Mix_LoadWAV("media/pikul.wav");
}
