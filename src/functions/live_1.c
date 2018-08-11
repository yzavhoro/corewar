/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:43:49 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/29 11:03:35 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		f_live(t_map *map, t_carry *carry)
{
	int		id;
	t_bot	*bot;

	carry->live++;
	id = convert_to_int(map->field, MV(carry->pos, 1));
	if ((bot = find_bot(map->bots, id)))
	{
		ft_printf("A process shows that player %d (%s) is alive\n",
				bot->id, bot->name);
		bot->live = map->cycle;
		bot->lives++;
	}
	map->nbr_live++;
	carry->pos = MV(carry->pos, 5);
}
