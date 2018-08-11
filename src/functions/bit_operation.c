/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-7-8bit_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:00:50 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/25 15:26:55 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int			init_buf(unsigned char *field, short pos,
		t_carry *carry, unsigned char *buf)
{
	static int i = -1;

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
	else if (get_arg(carry->codage, i) == T_DIR)
	{
		write_buf(field, pos, buf, 4);
		return (4);
	}
	else if (get_arg(carry->codage, i) == T_IND)
	{
		write_buf(field, MV(pos, convert_to_short(field, pos)), buf, 4);
		return (2);
	}
	return (0);
}

static void			bit_operation(unsigned char *dst,
		unsigned char *src, char operation)
{
	int				i;

	i = -1;
	if (operation == '&')
		while (++i < 4)
			dst[i] = dst[i] & src[i];
	else if (operation == '|')
		while (++i < 4)
			dst[i] = dst[i] | src[i];
	else if (operation == '^')
		while (++i < 4)
			dst[i] = dst[i] ^ src[i];
}

void				bit_function(t_map *map, t_carry *carry, char operation)
{
	unsigned char	buf1[4];
	unsigned char	buf2[4];
	int				b1;
	int				b2;

	b1 = init_buf(map->field, MV(carry->pos, 2), carry, buf1);
	b2 = init_buf(map->field, MV(carry->pos, b1 + 2), carry, buf2);
	if (b1 * b2 && valid_treg(map->field[MV(carry->pos, b1 + b2 + 2)] - 1))
	{
		bit_operation(buf1, buf2, operation);
		carry->reg[map->field[MV(carry->pos, b1 + b2 + 2)] - 1] =
			convert_to_reg(buf1, 0);
		carry->carry = !carry->reg[map->field[MV(carry->pos, b1 + b2 + 2)] - 1];
	}
	carry->pos = MV(carry->pos, shift(carry->codage, 4, carry->fun_id));
}
