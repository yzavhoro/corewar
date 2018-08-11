/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:43:47 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/25 15:43:51 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int			init_buf(unsigned char *field, int pos,
		t_carry *carry, unsigned char *buf)
{
	static int		i = -1;

	i++;
	if (i == 2)
		i = 0;
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
					MV(pos, convert_to_short(field, pos) % IDX_MOD), buf, 4);
		else
			write_buf(field, pos, buf, 2);
		return (2);
	}
	return (0);
}

void				f_ldi(t_map *map, t_carry *carry)
{
	unsigned char	buf1[4];
	unsigned char	buf2[4];
	int				b1;
	int				b2;
	int				sum;

	b1 = init_buf(map->field, MV(carry->pos, 2), carry, buf1);
	b2 = init_buf(map->field, MV(carry->pos, b1 + 2), carry, buf2);
	sum = get_value(get_arg(carry->codage, 0), buf1) +
		get_value(get_arg(carry->codage, 1), buf2);
	if (b1 * b2 && valid_treg(map->field[MV(carry->pos, b1 + b2 + 2)] - 1))
		carry->reg[map->field[MV(carry->pos, b1 + b2 + 2)] - 1] =
			convert_to_reg(map->field, MV(carry->pos, sum % IDX_MOD));
	carry->pos = MV(carry->pos, shift(carry->codage, 2, carry->fun_id));
}
