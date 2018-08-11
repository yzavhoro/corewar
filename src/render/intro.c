/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:33:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/06 14:33:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	get_3(t_sdl *sdl)
{
	sdl->map.cells[10 * MAP_SIZE + MAP_SIZE / 2 - 4].color = P3_C;
	sdl->map.cells[10 * MAP_SIZE + MAP_SIZE / 2 - 3].color = P3_C;
	sdl->map.cells[10 * MAP_SIZE + MAP_SIZE / 2 - 2].color = P3_C;
	sdl->map.cells[10 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P3_C;
	sdl->map.cells[11 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P3_C;
	sdl->map.cells[12 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P3_C;
	sdl->map.cells[13 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P3_C;
	sdl->map.cells[14 * MAP_SIZE + MAP_SIZE / 2 - 4].color = P3_C;
	sdl->map.cells[14 * MAP_SIZE + MAP_SIZE / 2 - 3].color = P3_C;
	sdl->map.cells[14 * MAP_SIZE + MAP_SIZE / 2 - 2].color = P3_C;
	sdl->map.cells[14 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P3_C;
	sdl->map.cells[15 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P3_C;
	sdl->map.cells[16 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P3_C;
	sdl->map.cells[17 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P3_C;
	sdl->map.cells[18 * MAP_SIZE + MAP_SIZE / 2 - 4].color = P3_C;
	sdl->map.cells[18 * MAP_SIZE + MAP_SIZE / 2 - 3].color = P3_C;
	sdl->map.cells[18 * MAP_SIZE + MAP_SIZE / 2 - 2].color = P3_C;
	sdl->map.cells[18 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P3_C;
	main_render(sdl);
	SDL_UpdateWindowSurface(sdl->window);
	SDL_Delay(1500);
}

void	get_2(t_sdl *sdl)
{
	sdl->map.cells[30 * MAP_SIZE + MAP_SIZE / 2 - 4].color = P2_C;
	sdl->map.cells[30 * MAP_SIZE + MAP_SIZE / 2 - 3].color = P2_C;
	sdl->map.cells[30 * MAP_SIZE + MAP_SIZE / 2 - 2].color = P2_C;
	sdl->map.cells[30 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P2_C;
	sdl->map.cells[31 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P2_C;
	sdl->map.cells[32 * MAP_SIZE + MAP_SIZE / 2 - 2].color = P2_C;
	sdl->map.cells[33 * MAP_SIZE + MAP_SIZE / 2 - 3].color = P2_C;
	sdl->map.cells[34 * MAP_SIZE + MAP_SIZE / 2 - 4].color = P2_C;
	sdl->map.cells[35 * MAP_SIZE + MAP_SIZE / 2 - 4].color = P2_C;
	sdl->map.cells[36 * MAP_SIZE + MAP_SIZE / 2 - 4].color = P2_C;
	sdl->map.cells[37 * MAP_SIZE + MAP_SIZE / 2 - 4].color = P2_C;
	sdl->map.cells[38 * MAP_SIZE + MAP_SIZE / 2 - 4].color = P2_C;
	sdl->map.cells[39 * MAP_SIZE + MAP_SIZE / 2 - 4].color = P2_C;
	sdl->map.cells[40 * MAP_SIZE + MAP_SIZE / 2 - 4].color = P2_C;
	sdl->map.cells[40 * MAP_SIZE + MAP_SIZE / 2 - 3].color = P2_C;
	sdl->map.cells[40 * MAP_SIZE + MAP_SIZE / 2 - 2].color = P2_C;
	sdl->map.cells[40 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P2_C;
	main_render(sdl);
	SDL_UpdateWindowSurface(sdl->window);
	SDL_Delay(1500);
}

void	get_1(t_sdl *sdl)
{
	sdl->map.cells[49 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P1_C;
	sdl->map.cells[50 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P1_C;
	sdl->map.cells[51 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P1_C;
	sdl->map.cells[52 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P1_C;
	sdl->map.cells[53 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P1_C;
	sdl->map.cells[54 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P1_C;
	sdl->map.cells[55 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P1_C;
	sdl->map.cells[56 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P1_C;
	sdl->map.cells[57 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P1_C;
	sdl->map.cells[58 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P1_C;
	sdl->map.cells[59 * MAP_SIZE + MAP_SIZE / 2 - 1].color = P1_C;
	main_render(sdl);
	SDL_UpdateWindowSurface(sdl->window);
	SDL_Delay(1500);
}

void	get_ready_to_rumble(t_sdl *sdl)
{
	main_render(sdl);
	ft_bzero(sdl->map.cells,
			sizeof(t_cell) * MAP_SIZE * MAP_SIZE);
	get_3(sdl);
	get_2(sdl);
	get_1(sdl);
	Mix_PlayChannel(-1, sdl->audio.fight, 0);
}
