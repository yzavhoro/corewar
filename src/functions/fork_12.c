/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:04:06 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/25 16:04:38 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	f_fork(t_map *map, t_carry *carry)
{
	add_carry(map, create_carry(carry->bot_id,
				carry->reg, carry->live, carry->carry));
	map->begin->pos = MV(carry->pos,
			convert_to_short(map->field, MV(carry->pos, 1)) % IDX_MOD);
	carry->pos = MV(carry->pos, 3);
	map->nbr_carries++;
}
