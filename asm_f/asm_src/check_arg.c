/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:20:58 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 14:20:59 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm_inc/asm.h"

/*
** Validate arguments of each instruction
*/

int		asm_check_arg_sec(char **line, int op)
{
	if (op == 3 && asm_check_reg(line, 1) && (asm_check_ind(line, 0) ||
	asm_check_reg(line, 0)))
		return (1);
	if ((op == 4 || op == 5) && asm_check_reg(line, 1) &&
	asm_check_reg(line, 1) && asm_check_reg(line, 0))
		return (1);
	if ((op == 10 || op == 14) && (asm_check_dir(line, op, 1) ||
	asm_check_reg(line, 1) || asm_check_ind(line, 1)) &&
	(asm_check_dir(line, op, 1) || asm_check_reg(line, 1)) &&
	asm_check_reg(line, 0))
		return (1);
	return (asm_error(8));
}

int		asm_check_arg(char **line, int op)
{
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if ((op == 1 || op == 9 || op == 12 || op == 15) &&
	asm_check_dir(line, op, 0))
		return (1);
	if ((op == 2 || op == 13) && (asm_check_dir(line, op, 1) ||
	asm_check_ind(line, 1)) && asm_check_reg(line, 0))
		return (1);
	if ((op == 6 || op == 7 || op == 8) && ((asm_check_dir(line, op, 1) ||
	asm_check_reg(line, 1) || asm_check_ind(line, 1))
	&& (asm_check_dir(line, op, 1) || asm_check_reg(line, 1) ||
	asm_check_ind(line, 1)) && asm_check_reg(line, 0)))
		return (1);
	if (op == 11 && asm_check_reg(line, 1) && (asm_check_dir(line, op, 1) ||
	asm_check_reg(line, 1) || asm_check_ind(line, 1)) &&
	(asm_check_dir(line, op, 0) || asm_check_reg(line, 0)))
		return (1);
	if (op == 16 && asm_check_reg(line, 0))
		return (1);
	return (asm_check_arg_sec(line, op));
}
