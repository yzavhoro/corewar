/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_bytes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:24:33 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/27 15:25:41 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		write_bytes(unsigned char *map, int pos, int src, short len)
{
	int		i;
	t_size	size;

	size.integer = src;
	i = -1;
	while (++i < len)
		map[MV(pos, i)] = size.b[3 - i];
}

void		write_id(char *map, int pos, unsigned char id, short len)
{
	int		i;

	i = -1;
	while (++i < len)
		map[MV(pos, i)] = id;
}

void		write_buf(unsigned char *map, int pos,
		unsigned char *dst, short len)
{
	int		i;

	i = -1;
	while (++i < len)
		dst[i] = map[MV(pos, i)];
}
