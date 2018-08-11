/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:59:42 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/25 16:03:28 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int			init_buf(unsigned char *field, int pos,
		t_carry *carry, unsigned char *buf)
{
	static int		i = 0;

	i++;
	if (i == 3)
		i = 1;
	ft_bzero(buf, 4);
	if (get_arg(carry->codage, i) == T_REG)
	{
		if (!valid_treg(field[pos] - 1))
			return (0);
		convert_to_char4(buf, carry->reg[field[pos] - 1]);
		return (1);
	}
	else if (get_arg(carry->codage, i) == T_DIR ||
			get_arg(carry->codage, i) == T_IND)
	{
		if (get_arg(carry->codage, i) == T_IND)
			write_buf(field,
					MV(0, convert_to_short(field, pos) % IDX_MOD), buf, 4);
		else
			write_buf(field, pos, buf, 2);
		return (2);
	}
	return (0);
}

void				f_sti(t_map *map, t_carry *carry)
{
	unsigned char	buf2[4];
	unsigned char	buf3[4];
	int				b2;
	int				b3;
	int				sum;

	b2 = init_buf(map->field, MV(carry->pos, 3), carry, buf2);
	b3 = init_buf(map->field, MV(carry->pos, b2 + 3), carry, buf3);
	sum = get_value(get_arg(carry->codage, 1), buf2) +
		get_value(get_arg(carry->codage, 2), buf3);
	if (b3 * b2 && valid_treg(map->field[MV(carry->pos, 2)] - 1))
	{
		write_bytes(map->field, MV(carry->pos, (sum % IDX_MOD)),
				carry->reg[(map->field[MV(carry->pos, 2)]) - 1], 4);
		write_id(map->cell_id,
				MV(carry->pos, (sum % IDX_MOD)), carry->bot_id, 4);
	}
	carry->pos = MV(carry->pos, shift(carry->codage, 2, carry->fun_id));
}
