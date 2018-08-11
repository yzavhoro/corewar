/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:18:16 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/07/28 16:01:18 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	init_fun(t_fun *f)
{
	f[0] = (t_fun){&f_live, 10, 4};
	f[1] = (t_fun){&f_ld, 5, 4};
	f[2] = (t_fun){&f_st, 5, 4};
	f[3] = (t_fun){&f_add, 10, 4};
	f[4] = (t_fun){&f_sub, 10, 4};
	f[5] = (t_fun){&f_and, 6, 4};
	f[6] = (t_fun){&f_or, 6, 4};
	f[7] = (t_fun){&f_xor, 6, 4};
	f[8] = (t_fun){&f_zjmp, 20, 2};
	f[9] = (t_fun){&f_ldi, 25, 2};
	f[10] = (t_fun){&f_sti, 25, 2};
	f[11] = (t_fun){&f_fork, 800, 2};
	f[12] = (t_fun){&f_lld, 10, 4};
	f[13] = (t_fun){&f_lldi, 50, 2};
	f[14] = (t_fun){&f_lfork, 1000, 2};
	f[15] = (t_fun){&f_aff, 2, 4};
}

static void	handle_flag(t_sdl *sdl)
{
	if (sdl->map.flag.name == 'd' && sdl->map.flag.n == sdl->map.cycle)
		dump_memory(&sdl->map);
	else if (sdl->map.flag.name == 'v' && sdl->map.cycle >= sdl->map.flag.n)
		main_loop(sdl);
}

void		do_death_checks(t_map *map)
{
	if (map->cycle == map->check_time)
	{
		if (check_time(map->bots))
		{
			map->cycle_to_die -= CYCLE_DELTA;
			map->check = -1;
		}
		carry_alive(map);
		map->nbr_live = 0;
		map->check++;
		map->check_time +=
		map->cycle_to_die > 0 ? map->cycle_to_die : 1;
	}
	if (map->check == MAX_CHECKS)
	{
		map->nbr_live = 0;
		map->check = 0;
		map->cycle_to_die -= CYCLE_DELTA;
	}
}

void		go_carries(t_map *map, t_fun *f)
{
	int		flag;
	t_carry	*carry;

	carry = map->begin;
	flag = 0;
	while (carry)
	{
		make_job(carry, map, f, &flag);
		carry = carry->next;
	}
	carry = map->begin;
	while (flag--)
	{
		make_job(carry, map, f, &flag);
		carry = carry->next;
	}
	carry = map->begin;
	while (carry)
	{
		init_carry_fun_id(carry, map, f);
		carry = carry->next;
	}
}

void		main_cycle(t_sdl *sdl)
{
	t_fun		f[16];
	t_bot		*bot;

	init_sdl_struct(sdl);
	init_fun(&f[0]);
	introduce_champs(sdl->map.bots);
	while (sdl->map.cycle_to_die > 0 && sdl->map.begin && !sdl->quit)
	{
		while (sdl->pause)
			while (SDL_PollEvent(&sdl->event))
				main_loop_events(sdl);
		go_carries(&sdl->map, f);
		do_death_checks(&sdl->map);
		handle_flag(sdl);
		init_struct_for_mtupikov(&sdl->map, sdl->map.begin);
		sdl->map.cycle++;
	}
	bot = sdl->map.bots;
	while (bot)
	{
		bot->is_alive = DYING;
		bot = bot->next;
	}
	bot = print_winner(sdl->map.bots);
	sdl->map.flag.name == 'v' ? vis_winner(sdl, bot) : 0;
}
