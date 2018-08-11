/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:16:35 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/27 15:24:27 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void	step(int *shift, unsigned char codage, char label, int i)
{
	if (get_arg(codage, i) == T_DIR)
		*shift += label;
	else if (get_arg(codage, i) == T_REG)
		*shift += 1;
	else if (get_arg(codage, i) == T_IND)
		*shift += 2;
}

int			shift(unsigned char codage, char label, int fun_id)
{
	int		shift;
	int		i;

	i = -1;
	shift = 2;
	if (fun_id == 0)
		return (5);
	else if (fun_id == 8 || fun_id == 11 || fun_id == 14)
		return (3);
	while (++i < 2)
		step(&shift, codage, label, i);
	if (fun_id != 1 && fun_id != 2 && fun_id != 12 && fun_id != 15)
		step(&shift, codage, label, i);
	return (shift);
}
