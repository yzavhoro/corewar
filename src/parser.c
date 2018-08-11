/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 16:32:39 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/28 15:35:00 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/vm.h"

char	get_flag(char *str)
{
	if (!ft_strcmp(str, "-dump"))
		return ('d');
	if (!ft_strcmp(str, "-v"))
		return ('v');
	if (!ft_strcmp(str, "-n"))
		return ('n');
	if (!ft_strcmp(str, "-a"))
		return ('a');
	print_error(4, 0, str);
	return (0);
}

void	validate_flags(t_map *map, int *i, char **argv, int bot_id)
{
	if (get_flag(argv[*i]) != 'n')
	{
		map->flag.name = get_flag(argv[*i]);
		if (argv[*i + 1] && OUTPUT_MODE(map->flag.name) &&
			ft_rank(ft_atoi(argv[*i + 1])) == (int)ft_strlen(argv[*i + 1]))
			map->flag.n = ft_atoi(argv[++(*i)]);
	}
	else
	{
		if (argv[*i + 1] && argv[*i + 2] && ft_rank(ft_atoi(argv[*i + 1])) ==
			(int)ft_strlen(argv[*i + 1])
			&& valid_n(map->map_id, ft_atoi(argv[*i + 1])))
		{
			map->map_id[bot_id] = ft_atoi(argv[++(*i)]);
		}
		else
			print_error(6, 0, 0);
	}
}

void	parse(int argc, char **argv, t_map *map)
{
	t_bot	*bot;
	int		fd;
	int		i;
	int		bot_id;

	bot = NULL;
	i = 0;
	bot_id = 0;
	argc == 1 ? print_error(0, 0, NULL) : NULL;
	while (argv[++i])
	{
		if (argv[i][0] != '-')
		{
			fd = open(argv[i], O_RDONLY);
			add_bot(&bot, create_bot(fd, argv[i], ++bot_id));
			add_carry(map, create_carry(bot_id, 0, 0, 1));
		}
		else
			validate_flags(map, &i, argv, bot_id);
	}
	if (bot)
		map->bots = bot;
	else
		print_error(5, 0, 0);
	flag_n(bot, map->map_id);
}
