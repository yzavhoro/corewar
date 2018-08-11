/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:04:53 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/25 16:05:58 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				f_lld(t_map *map, t_carry *carry)
{
	unsigned short	nb;

	if (get_arg(carry->codage, 0) == T_DIR &&
			valid_treg(map->field[MV(carry->pos, 6)] - 1))
	{
		carry->reg[map->field[MV(carry->pos, 6)] - 1] =
			convert_to_reg(map->field, MV(carry->pos, 2));
		carry->carry = !(carry->reg[map->field[MV(carry->pos, 6)] - 1]);
		carry->pos = MV(carry->pos, 7);
	}
	else if (get_arg(carry->codage, 0) == T_IND &&
			valid_treg(map->field[MV(carry->pos, 4)] - 1))
	{
		nb = convert_to_short(map->field, MV(carry->pos, 2));
		carry->reg[map->field[MV(carry->pos, 4)] - 1] =
			convert_to_reg(map->field, MV(carry->pos, nb));
		carry->carry = !(carry->reg[map->field[MV(carry->pos, 4)] - 1]);
		carry->pos = MV(carry->pos, 5);
	}
	else
		carry->pos = MV(carry->pos, 1);
}
