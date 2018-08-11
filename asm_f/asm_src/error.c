/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:20:39 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 14:20:41 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm_inc/asm.h"

int		asm_error_sec(int error)
{
	if (error == 11)
		ft_printf("No name or comment.\n");
	if (error == 12)
		ft_printf("No argument (or too much) for instruction -> line: %d.\n",
		g_line);
	if (error == 13)
		ft_printf("Multiple lines on name or comment.\n");
	if (error == 14)
		ft_printf("Wrong file extension.\n");
	if (error == 15)
		ft_printf("No LABEL_CHAR.\n");
	exit(0);
	return (0);
}

int		asm_error(int error)
{
	if (error == 1)
		ft_printf("Wrong format name -> line: %d.\n", g_line);
	if (error == 2)
		ft_printf("Wrong format comment -> line: %d.\n", g_line);
	if (error == 3)
		ft_printf("Wrong format LABEL_CHARS -> line: %d.\n", g_line);
	if (error == 4)
		ft_printf("Wrong format LABEL_CHAR -> line: %d.\n", g_line);
	if (error == 5)
		ft_printf("Wrong name of instruct -> line: %d.\n", g_line);
	if (error == 7)
		ft_printf("Not an indirect -> line: %d.\n", g_line);
	if (error == 8)
		ft_printf("Wrong arguments -> line: %d.\n", g_line);
	if (error == 9)
		ft_printf("Duplicate label.\n");
	if (error == 10)
		ft_printf("No match between labels.\n");
	return (asm_error_sec(error));
}
