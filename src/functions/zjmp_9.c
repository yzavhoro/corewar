/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_zjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:59:26 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/25 14:59:35 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	f_zjmp(t_map *map, t_carry *carry)
{
	int mv;

	mv = 3;
	if (carry->carry)
	{
		mv = convert_to_short(map->field, MV(carry->pos, 1));
		mv %= IDX_MOD;
	}
	carry->pos = MV(carry->pos, mv);
}
