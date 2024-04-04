/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:50:38 by mapale            #+#    #+#             */
/*   Updated: 2024/04/03 17:58:41 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hm_line(char *path)
{
	int		cnt;
	int		fd;
	char	*l;

	cnt = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	l = get_next_line(fd);
	while (l)
	{
		cnt++;
		free(l);
		l = get_next_line(fd);
	}
	free(l);
	close(fd);
	return (cnt);
}

char	**get_map(char *path, t_sl *sl)
{
	int		i;
	int		fd;
	char	*l;
	char	**map;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(1);
	l = get_next_line(fd);
	map = malloc(sizeof(char *) * sl->map.height);
	if (!map)
		return (NULL);
	while (l && i < sl->map.height)
	{
		map[i] = ft_strdup(l);
		if (!map[i])
			return (free_map(sl), NULL);
		free(l);
		l = get_next_line(fd);
		i++;
	}
	free(l);
	close(fd);
	return (map);
}

int	is_it_closed(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_char(char c, t_sl *sl)
{
	if (c == '0' || c == '1' || c == 'K')
		return (1);
	if (c == 'C')
		return (sl->characs.collectibles++, 1);
	if (c == 'E')
	{
		if (sl->characs.map_exit != 0)
			return (error(sl, "Error\n\
Too many Exits: only one is allowed, change the map boo\n"));
		return (sl->characs.map_exit++, 1);
	}
	if (c == 'P')
	{
		if (sl->characs.player != 0)
			return (error(sl, "Error\n\
Too many Players: only one is allowed, change the map pookie\n"));
		return (sl->characs.player++, 1);
	}
	return (error(sl, "Error\nStick to the allowed characters,\
do not pull some out your hat\n"));
}

int	check_line(char *line, t_sl *sl)
{
	int	i;

	i = 0;
	if (sl->map.height == 0)
		if (!is_it_closed(line))
			return (0);
	if (line[i] != '1' || line[ft_strlen(line) - 2] != '1')
		return (error(sl, "Error\n\
I swear on the holy Slayness if you don't close that damned map!\n"));
	i++;
	while (line[i] && line[i] != '\n')
	{
		if (!valid_char(line[i], sl))
			return (0);
		i++;
	}
	return (1);
}
