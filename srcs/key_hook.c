/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:03:28 by mapale            #+#    #+#             */
/*   Updated: 2024/03/25 14:50:44 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	call(char **map, t_sl *sl, int x, int y)
{
	if (x == -1)
		up(map, sl);
	if (x == 1)
		down(map, sl);
	if (y == -1)
		right(map, sl);
	if (y == 1)
		left(map, sl);
}

void	game_finished(t_sl *sl)
{
	ft_putstr("You did it hoe congrats\n(Your Mum played better tho)\n");
	close_window(sl);
}

void	move_character(t_sl *sl, int x, int y)
{
	t_vect old_pos;

	if (sl->characs.collectibles == 0 && sl->map.graph[sl->player.x + x][sl->player.y + y] == 'e')
		game_finished(sl);
	if (sl->map.graph[sl->player.x + x][sl->player.y + y] == 'e' || sl->map.graph[sl->player.x + x][sl->player.y + y] == '1')
		return ;
	old_pos.x = sl->player.x;
	old_pos.y = sl->player.y;
	sl->player.x += x;
	sl->player.y += y;
	if (sl->map.graph[sl->player.x][sl->player.y] == 'c')
		sl->characs.collectibles --;
	sl->map.graph[sl->player.x][sl->player.y] = 'p';
	sl->map.graph[old_pos.x][old_pos.y] = '.';
	call(sl->map.graph, sl, x, y);
}

int	key_hook(int kc, t_sl *sl)
{
	if (kc == KEY_ESC)
		return (close_window(sl));
	if (sl->player.x <= 0 || sl->player.y <= 0 || sl->player.x >= sl->map.height|| sl->player.y >= sl->map.width)
		return (0);
	if (kc == KEY_UP)
		move_character(sl, -1, 0);
	if (kc == KEY_DOWN)
		move_character(sl, 1, 0);
	if (kc == KEY_LEFT)
		move_character(sl, 0, -1);
	if (kc == KEY_RIGHT)
		move_character(sl, 0, 1);
	return (0);
}
