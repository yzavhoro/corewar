/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boring_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:50:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/06 16:50:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int			*get_rgb(int col)
{
	int *k;

	k = malloc(sizeof(int) * 3);
	k[0] = col / (int)pow(256, 2);
	k[1] = col / (256 % (int)pow(256, 2));
	k[2] = col % 256;
	return (k);
}

void		load_boring_bg(t_sdl *sdl)
{
	SDL_BlitScaled(sdl->bor_bg, NULL, sdl->screen, NULL);
}

char		*get_num(int n)
{
	char *n_itoa;
	char *ret;

	n_itoa = ft_itoa_base(n, 16);
	if (ft_strlen(n_itoa) == 2)
		return (n_itoa);
	ret = (char *)malloc(sizeof(char) * 3);
	ret[0] = '0';
	ret[1] = n_itoa[0];
	ret[2] = '\0';
	ft_strdel(&n_itoa);
	return (ret);
}

int			render_util_f(t_sdl *sdl, int i, int j)
{
	if (sdl->map.cells[i * MAP_SIZE + j].is_carry == CARRET)
		return (2);
	else
		return (1);
}

void		render_boring_map(t_sdl *sdl)
{
	int			i;
	int			j;
	int			*k;
	int			f;
	char		*num;

	i = -1;
	while (++i < MAP_SIZE)
	{
		j = -1;
		while (++j < MAP_SIZE)
		{
			f = render_util_f(sdl, i, j);
			num = get_num(sdl->map.cells[i * MAP_SIZE + j].c);
			k = get_rgb(sdl->map.cells[i * MAP_SIZE + j].color);
			put_map_info(sdl, f, num,
			(int[]){j * 23 + 55, i * 15 + 50, 15, k[0], k[1], k[2]});
			free(k);
			ft_strdel(&num);
		}
		SDL_Delay(sdl->rend_speed);
	}
}
