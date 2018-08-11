/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:22:05 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 14:22:10 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm_inc/asm.h"

void	asm_init_global(void)
{
	g_line = 0;
	g_pos = 0;
	g_temp = 0;
}

int		main(int argc, char **argv)
{
	t_header	*head;
	int			index;

	index = 1;
	asm_init_global();
	if (argc > 1)
	{
		while (index < argc)
		{
			head = asm_header_init();
			if (asm_parsing(argv[index++], head) == -1)
				ft_printf("Usage: ./asm <champion>.s\n");
			free(head);
			asm_init_global();
		}
	}
	else
		ft_printf("Usage: ./asm <champion>.s\n");
	return (0);
}
