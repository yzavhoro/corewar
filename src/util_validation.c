/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 16:38:58 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/07/27 16:39:03 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	valid_treg(unsigned char byte)
{
	return (byte >= 0 && byte < 16);
}

int	valid_fun_id(int id)
{
	return (id > 0 && id <= 16);
}

int	valid_codage(int id, unsigned char codage)
{
	if (id == 1 || id == 9 || id == 12 || id == 15)
		return (1);
	else if (id == 2)
		return (LD(codage));
	else if (id == 3)
		return (ST(codage));
	else if (id == 4)
		return (ADD(codage));
	else if (id == 5)
		return (SUB(codage));
	else if (id == 6)
		return (AND(codage));
	else if (id == 7)
		return (OR(codage));
	else if (id == 8)
		return (XOR(codage));
	else if (id == 10)
		return (LDI(codage));
	else if (id == 11)
		return (STI(codage));
	else if (id == 13)
		return (LLD(codage));
	else if (id == 14 || id == 16)
		return (id == 14 ? LLDI(codage) : AFF(codage));
	return (0);
}

int	valid_n(int *map, int id)
{
	int i;

	if (id < 1 || id > 4)
		return (0);
	i = -1;
	while (++i < 4)
		if (map[i] == id)
			return (0);
	return (1);
}
