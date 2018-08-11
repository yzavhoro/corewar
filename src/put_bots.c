/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 16:56:24 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/27 16:57:20 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	count_bots(t_bot *bot)
{
	int		i;

	i = 0;
	while (bot)
	{
		bot = bot->next;
		i++;
	}
	return (i);
}

void		put_bots(t_map *map, t_bot *bot)
{
	int		i;
	int		b;
	t_carry	*carry;

	carry = map->begin;
	ft_bzero(map->field, FIELD_SIZE);
	ft_bzero(map->cell_id, FIELD_SIZE);
	i = FIELD_SIZE / count_bots(bot);
	b = 0;
	while (carry->next)
		carry = carry->next;
	map->end = carry;
	while (bot)
	{
		bot->id = -bot->id;
		carry->reg[0] = bot->id;
		ft_strcpy_cw(map->field + (i * b), bot->code, bot->size_code);
		ft_memset(map->cell_id + (i * b), carry->bot_id, bot->size_code);
		carry->pos = i * b;
		b++;
		bot = bot->next;
		carry = carry->prev;
	}
}
