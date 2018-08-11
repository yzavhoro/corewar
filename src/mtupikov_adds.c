/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtupikov_adds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:19:40 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/07/25 13:19:46 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	init_struct_for_mtupikov(t_map *map, t_carry *tmp)
{
	int	i;

	i = -1;
	while (++i < 4096)
	{
		map->cells[i].c = map->field[i];
		map->cells[i].player_num = map->cell_id[i];
		if (map->cells[i].player_num - 1 == 0)
			map->cells[i].color = P1_C;
		else if (map->cells[i].player_num - 1 == 1)
			map->cells[i].color = P2_C;
		else if (map->cells[i].player_num - 1 == 2)
			map->cells[i].color = P3_C;
		else if (map->cells[i].player_num - 1 == 3)
			map->cells[i].color = P4_C;
		else
			map->cells[i].color = EM_C;
		map->cells[i].is_carry = 0;
	}
	while (tmp)
	{
		map->cells[tmp->pos].is_carry = 1;
		tmp = tmp->next;
	}
}
