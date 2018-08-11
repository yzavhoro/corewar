/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:53:45 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/27 16:27:44 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		add_carry(t_map *map, t_carry *carry)
{
	carry->next = map->begin;
	if (map->begin)
		map->begin->prev = carry;
	map->begin = carry;
	map->nbr_carries++;
}

t_carry		*create_carry(unsigned char id, int *reg, int live, char c)
{
	t_carry			*carry;
	static unsigned	bot_id = 0;
	static int		ids = 0;

	carry = (t_carry*)malloc(sizeof(t_carry));
	carry->id = ids++;
	ft_bzero(carry->reg, sizeof(carry->reg));
	if (reg)
		ft_intcpy(carry->reg, reg, 16);
	else
		carry->reg[0] = --bot_id;
	carry->bot_id = id;
	carry->live = live;
	carry->carry = c;
	carry->fun_cycle = 0;
	carry->fun_id = -1;
	carry->next = NULL;
	carry->prev = NULL;
	return (carry);
}

void		delete_carry(t_carry **carry)
{
	if ((*carry)->prev && (*carry)->next)
	{
		(*carry)->prev->next = (*carry)->next;
		(*carry)->next->prev = (*carry)->prev;
	}
	else if ((*carry)->prev)
		(*carry)->prev->next = NULL;
	else if ((*carry)->next)
		(*carry)->next->prev = NULL;
	free(*carry);
}

int			carry_alive(t_map *map)
{
	t_carry *first;
	t_carry *tmp;
	t_carry *del;

	first = map->begin;
	tmp = map->begin;
	while (tmp)
	{
		if (!tmp->live)
		{
			if (!tmp->prev)
				first = tmp->next;
			del = tmp;
			tmp = tmp->next;
			delete_carry(&del);
			map->nbr_carries--;
		}
		else
		{
			tmp->live = 0;
			tmp = tmp->next;
		}
	}
	map->begin = first;
	return (map->begin != NULL);
}
