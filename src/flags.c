/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:17:08 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/07/28 15:29:51 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	dump_memory(t_map *map)
{
	int i;

	ft_printf("0x");
	i = -1;
	while (++i < FIELD_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("%#.4x : ", i);
		ft_printf("%-3.2x", map->field[i]);
		if (i % 64 == 63)
			ft_printf("\n");
	}
	exit(0);
}

void	flag_n(t_bot *bot, int *map)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		if (valid_n(map, i + 1))
		{
			j = -1;
			while (++j < 4)
			{
				if (map[j] == 0)
				{
					map[j] = i + 1;
					break ;
				}
			}
		}
	}
	i = -1;
	while (bot)
	{
		bot->id = map[++i];
		bot = bot->next;
	}
}
