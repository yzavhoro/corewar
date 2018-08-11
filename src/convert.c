/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 16:29:52 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/27 16:31:28 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			convert_to_int(unsigned char *map, int pos)
{
	t_size	size;

	size.b[0] = map[MV(pos, 3)];
	size.b[1] = map[MV(pos, 2)];
	size.b[2] = map[MV(pos, 1)];
	size.b[3] = map[pos];
	return (size.integer);
}

int			convert_to_reg(unsigned char *map, int pos)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (i < 4)
	{
		res = res << 8 | map[MV(pos, i)];
		i++;
	}
	return (res);
}

short		convert_to_short(unsigned char *map, int pos)
{
	t_size	size;

	size.i[0] = map[MV(pos, 1)];
	size.i[1] = map[pos];
	return (size.s);
}

void		convert_to_char4(unsigned char *dst, int src)
{
	t_size	size;

	size.integer = src;
	dst[0] = size.b[3];
	dst[1] = size.b[2];
	dst[2] = size.b[1];
	dst[3] = size.b[0];
}
