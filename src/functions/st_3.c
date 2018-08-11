/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:26:34 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/27 15:26:46 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		f_st(t_map *map, t_carry *carry)
{
	int		t_reg;
	int		t_ind;

	if (valid_treg(map->field[MV(carry->pos, 2)] - 1))
	{
		t_reg = carry->reg[map->field[MV(carry->pos, 2)] - 1];
		if (get_arg(carry->codage, 1) == T_IND)
		{
			t_ind = convert_to_short(map->field, MV(carry->pos, 3)) % IDX_MOD;
			write_bytes(map->field, MV(carry->pos, t_ind), t_reg, 4);
			write_id(&map->cell_id[0], MV(carry->pos, t_ind), carry->bot_id, 4);
		}
		else if (get_arg(carry->codage, 1) == T_REG)
			carry->reg[map->field[MV(carry->pos, 3)] - 1] = t_reg;
	}
	carry->pos = MV(carry->pos, shift(carry->codage, 4, carry->fun_id));
}
