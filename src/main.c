/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:17:51 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/07/28 15:04:51 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	init_vis(t_sdl *sdl)
{
	sdl->th = 0;
	sdl->tr = 0;
	sdl->winner = 0;
	sdl->quit = 0;
	sdl->frame_4 = 0;
	sdl->frame_6 = 0;
	sdl->whoopie = 0;
	sdl->autoplay = 0;
	sdl->rend_speed = 1;
	sdl->map.flag.n = 0;
	sdl->map.begin = NULL;
	sdl->map.nbr_carries = 0;
}

int		main(int argc, char **argv)
{
	t_sdl	sdl;

	init_vis(&sdl);
	parse(argc, argv, &sdl.map);
	if (sdl.map.flag.name == 'v')
	{
		if (!init_sdl(&sdl))
			exit(2);
		load_images(&sdl);
		load_music(&sdl);
		sdl.map.vis_mode = 1;
	}
	else
		sdl.map.vis_mode = 0;
	put_bots(&sdl.map, sdl.map.bots);
	main_cycle(&sdl);
	return (0);
}
