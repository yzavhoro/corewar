/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:14:29 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/30 13:14:31 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#include <stdio.h>

void	main_render(t_sdl *sdl)
{
	load_bg(sdl);
	put_players(sdl);
	render_map(sdl);
}

void	boring_render(t_sdl *sdl)
{
	load_boring_bg(sdl);
	render_boring_map(sdl);
	print_boring_stuff(sdl);
}

void	main_loop(t_sdl *sdl)
{
	while (SDL_PollEvent(&sdl->event))
		main_loop_events(sdl);
	if (!sdl->boring_mode)
	{
		main_render(sdl);
		frame_inc(sdl);
	}
	else
		boring_render(sdl);
	if (sdl->winner > 0 && !sdl->boring_mode)
		winner_render(sdl);
	if (sdl->whoopie)
		pikul(sdl);
	SDL_UpdateWindowSurface(sdl->window);
}
