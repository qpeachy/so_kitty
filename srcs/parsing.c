/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:01:14 by mapale            #+#    #+#             */
/*   Updated: 2024/03/26 13:01:41 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_the_count_good(char **m, t_sl *sl)
{
	if(sl->characs.map_exit < 1)
		return (error(sl, "Error\n No exit? It will create itself?\n"));
	if(sl->characs.collectibles < 1)
		return (error(sl, "Error\n Why is there no collectibles bruv?\n"));
	if(sl->characs.player < 1)
		return (error(sl, "Error\n Unless you want her to crush your head, Kitty needs to know where to sprout mandem\n"));
	return (pre_doable(sl, m));
}

int	w_line(t_sl *sl, char *read)
{
	int	line;

	line = 0;
	if (!check_line(read, sl))
			return (0);
	while (read[line])
		line++;
	if (line > sl->map.width)
		sl->map.width = line;
	return (1);
}

int	is_map_valid(char **map, t_sl *sl)
{
	int	line;

	line = 0;
	//printf("line = %s| size = %d\n", map[line], ft_strlen(map[line]));
	sl->map.width = ft_strlen(map[line]);
	while (line < sl->map.height)
	{
		if ((line == sl->map.height - 1 && sl->map.width - 1 != ft_strlen(map[line]))
			|| (line != sl->map.height - 1 && sl->map.width != ft_strlen(map[line])))
			return(error(sl, "Error\nDoes equality makes you queasy? Don't care your map width should be the same\n"));
		if (!w_line(sl, map[line]))
			return(free_map(sl), 0);
		line++;
		//printf("line = %s\n", map[line]);
	}
	if (!is_it_closed(map[line - 1]))
		return (free_map(sl), error(sl, "Error\nYou known how to close a door right? Then close this damned map thanks"));
	return (is_the_count_good(map,sl));
}

int	pre_check_map(char ** m, t_sl *sl)
{
	sl->characs.map_exit = 0;
	sl->characs.player = 0;
	sl->characs.collectibles = 0;
	return(is_map_valid(m, sl));
}
