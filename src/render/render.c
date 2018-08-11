/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 23:54:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/05 23:54:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			put_image(t_sdl *sdl, SDL_Surface *surface, int c[4])
{
	SDL_Rect stretch_rect;

	stretch_rect.x = c[0];
	stretch_rect.y = c[1];
	stretch_rect.w = c[2];
	stretch_rect.h = c[3];
	SDL_BlitScaled(surface, NULL, sdl->screen, &stretch_rect);
}

SDL_Surface		*get_surface(t_sdl *sdl, int i, int j)
{
	if (sdl->map.cells[i * MAP_SIZE + j].color == P1_C)
		return (sdl->red);
	else if (sdl->map.cells[i * MAP_SIZE + j].color == P2_C)
		return (sdl->green);
	else if (sdl->map.cells[i * MAP_SIZE + j].color == P3_C)
		return (sdl->blue);
	else if (sdl->map.cells[i * MAP_SIZE + j].color == P4_C)
		return (sdl->yellow);
	else if (sdl->map.cells[i * MAP_SIZE + j].color == EM_C)
		return (sdl->grey);
	else if (sdl->map.cells[i * MAP_SIZE + j].color == P1_C_L)
		return (sdl->red_l);
	else if (sdl->map.cells[i * MAP_SIZE + j].color == P2_C_L)
		return (sdl->green_l);
	else if (sdl->map.cells[i * MAP_SIZE + j].color == P3_C_L)
		return (sdl->blue_l);
	else if (sdl->map.cells[i * MAP_SIZE + j].color == P4_C_L)
		return (sdl->yellow_l);
	else
		return (sdl->grey_l);
}

/*
**	MAGIC HAPPENS HERE!
*/

void			render_map(t_sdl *sdl)
{
	t_render r;

	r = (t_render){-1, -1, 0, 530, 65, 530, 65};
	while (++r.i < MAP_SIZE)
	{
		r.j = -1;
		r.pi = r.ppi;
		r.pj = r.ppj;
		while (++r.j < MAP_SIZE)
		{
			if (sdl->map.cells[r.i * MAP_SIZE + r.j].is_carry == CARRET)
				r.k = 10;
			else
				r.k = 0;
			put_image(sdl, get_surface(sdl, r.i, r.j), (int[]){(int)r.pj,
							(int)(r.pi + tan(drand48()) - r.k), 30, 30});
			r.pj += 14.3;
			r.pi -= 8.1;
		}
		r.ppi += 7.8;
		r.ppj += 13.82;
		SDL_Delay(sdl->rend_speed);
	}
}
