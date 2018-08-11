/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:15:57 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/29 11:03:54 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	f_aff(t_map *map, t_carry *carry)
{
	if (valid_treg(map->field[MV(carry->pos, 2)] - 1) && map->flag.name == 'a')
		ft_printf("Aff: %c\n",
				carry->reg[map->field[MV(carry->pos, 2)] - 1] % 256);
	carry->pos = MV(carry->pos, 3);
}
