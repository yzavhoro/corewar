/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 16:17:25 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/07/27 16:17:27 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		init_carry_fun_id(t_carry *carry, t_map *map, t_fun *f)
{
	if (carry->fun_cycle <= map->cycle)
	{
		if (!valid_fun_id(map->field[carry->pos]))
		{
			carry->pos = MV(carry->pos, 1);
			carry->fun_id = -1;
		}
		else
		{
			carry->fun_id = map->field[carry->pos] - 1;
			carry->fun_cycle = f[carry->fun_id].cycle + map->cycle;
		}
	}
}

void		make_job(t_carry *carry, t_map *map, t_fun *f, int *flag)
{
	if (carry->fun_cycle <= map->cycle)
	{
		if (map->cycle && carry->fun_id != -1)
		{
			carry->codage = map->field[MV(carry->pos, 1)];
			if (valid_codage(carry->fun_id + 1, map->field[MV(carry->pos, 1)]))
			{
				f[carry->fun_id].fun(map, carry);
				if (carry->fun_id == 11 || carry->fun_id == 14)
					(*flag)++;
			}
			else
			{
				carry->pos = MV(carry->pos, shift(carry->codage,
					f[carry->fun_id].label, carry->fun_id));
				carry->fun_id = -1;
			}
		}
	}
}

void		init_sdl_struct(t_sdl *sdl)
{
	sdl->pause = 0;
	sdl->map.cycle = 0;
	sdl->map.cycle_to_die = CYCLE_TO_DIE;
	sdl->map.check_time = CYCLE_TO_DIE;
	sdl->map.check = 0;
	sdl->map.nbr_live = 0;
	if (sdl->map.vis_mode)
	{
		get_ready_to_rumble(sdl);
		Mix_PlayMusic(sdl->audio.music, -1);
	}
}

int			check_time(t_bot *bot)
{
	int flag;

	flag = 0;
	while (bot)
	{
		if (bot->lives >= NBR_LIVE)
			flag = 1;
		bot->lives = 0;
		bot = bot->next;
	}
	return (flag);
}
