/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:20:36 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/07/28 17:04:23 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			get_arg(unsigned char arg, int id)
{
	arg = arg << 2 * id;
	if (arg >> 7 && (char)(arg << 1) >> 7)
		return (T_IND);
	else if (arg >> 7)
		return (T_DIR);
	if (!(arg >> 7) && (char)(arg << 1) >> 7)
		return (T_REG);
	return (0);
}

int			get_value(int arg, unsigned char *buf)
{
	int l;

	if (arg == T_DIR)
		l = convert_to_short(buf, 0);
	else
		l = convert_to_reg(buf, 0);
	return (l);
}

int			check_magic(unsigned char *skip)
{
	return (!skip[0] && skip[1] == 0xea && skip[2] == 0x83 && skip[3] == 0xf3);
}

void		ft_intcpy(int *dst, int *src, int len)
{
	while (len--)
		dst[len] = src[len];
}

void		vis_winner(t_sdl *sdl, t_bot *bot)
{
	bot->is_alive = ALIVE;
	sdl->winner = -bot->id;
	while (!sdl->quit)
	{
		while (SDL_PollEvent(&sdl->event))
			main_loop_events(sdl);
		main_loop(sdl);
	}
}
