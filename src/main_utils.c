/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:53:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/30 12:53:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	error(char *line)
{
	ft_printf(line);
	exit(2);
}

void	frame_inc(t_sdl *sdl)
{
	sdl->frame_6++;
	if (sdl->frame_6 >= 6)
		sdl->frame_6 = 0;
	sdl->frame_4++;
	if (sdl->frame_4 >= 4)
		sdl->frame_4 = 0;
}

void	events_util_2(t_sdl *sdl)
{
	if (sdl->event.type == SDL_KEYDOWN)
	{
		if (sdl->event.key.keysym.sym == SDLK_1)
		{
			sdl->pause = 0;
			sdl->rend_speed = 0;
		}
		if (sdl->event.key.keysym.sym == SDLK_2)
		{
			sdl->pause = 0;
			sdl->rend_speed = 1;
		}
		if (sdl->event.key.keysym.sym == SDLK_3)
		{
			sdl->pause = 0;
			sdl->rend_speed = 2;
		}
		if (sdl->event.key.keysym.sym == SDLK_4)
		{
			sdl->pause = 0;
			sdl->rend_speed = 3;
		}
		if (sdl->event.key.keysym.sym == SDLK_5)
			sdl->pause = !sdl->pause;
	}
}

void	events_util(t_sdl *sdl)
{
	if ((sdl->event.type == SDL_KEYDOWN &&
		sdl->event.key.keysym.sym == SDLK_q))
	{
		sdl->whoopie = 1;
	}
	if ((sdl->event.type == SDL_KEYDOWN &&
		sdl->event.key.keysym.sym == SDLK_a))
	{
		if (!sdl->autoplay)
			sdl->autoplay = 1;
		else
			sdl->autoplay = 0;
	}
	events_util_2(sdl);
}

void	main_loop_events(t_sdl *sdl)
{
	if ((sdl->event.type == SDL_KEYDOWN &&
		sdl->event.key.keysym.sym == SDLK_TAB))
	{
		if (!sdl->boring_mode)
		{
			sdl->boring_mode = 1;
			Mix_PauseMusic();
		}
		else
		{
			sdl->boring_mode = 0;
			Mix_ResumeMusic();
		}
	}
	else if (sdl->event.type == SDL_QUIT || (sdl->event.type == SDL_KEYDOWN &&
			(sdl->event.key.keysym.sym == SDLK_ESCAPE))
			|| (sdl->event.type == SDL_KEYDOWN && sdl->winner > 0))
	{
		sdl->quit = 1;
		sdl->pause = 0;
	}
	events_util(sdl);
}
