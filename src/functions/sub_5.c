/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:57:05 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/25 14:57:31 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	f_sub(t_map *map, t_carry *carry)
{
	if (valid_treg(map->field[MV(carry->pos, 2)] - 1)
		&& valid_treg(map->field[MV(carry->pos, 3)] - 1)
		&& valid_treg(map->field[MV(carry->pos, 4)] - 1))
	{
		carry->reg[map->field[MV(carry->pos, 4)] - 1] =
		carry->reg[map->field[MV(carry->pos, 2)] - 1] -
		carry->reg[map->field[MV(carry->pos, 3)] - 1];
		carry->carry = !carry->reg[map->field[MV(carry->pos, 4)] - 1];
	}
	carry->pos = MV(carry->pos, 5);
}
