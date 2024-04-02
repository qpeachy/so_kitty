/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:03:28 by mapale            #+#    #+#             */
/*   Updated: 2024/04/02 17:43:59 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	call_last(t_sl *sl, int x, int y)
{
	if (x == -1)
		up(sl->map.graph, sl, 1);
	if (x == 1)
		down(sl->map.graph, sl, 1);
	if (y == -1)
		right(sl->map.graph, sl, 1);
	if (y == 1)
		left(sl->map.graph, sl, 1);
}

void	call_first(t_sl *sl, int x, int y)
{
	if (x == -1)
		up(sl->map.graph, sl, 0);
	if (x == 1)
		down(sl->map.graph, sl, 0);
	if (y == -1)
		right(sl->map.graph, sl, 0);
	if (y == 1)
		left(sl->map.graph, sl, 0);
}

void	game_finished(t_sl *sl)
{
	putstr_fd("You did it babe congrats\n");
	putstr_fd("(Hope your dating game's better tho)\n");
	close_window(sl);
}

void	move_character(t_sl *sl, int x, int y)
{
	t_vect	old_pos;

	sl->move.move++;
	init_move(sl);
	call_first(sl, x, y);
	if (sl->map.graph[sl->player.x + x][sl->player.y + y] == 'k')
		kitty_died(sl);
	if (sl->characs.collectibles == 0 \
		&& sl->map.graph[sl->player.x + x][sl->player.y + y] == 'e')
		game_finished(sl);
	if (sl->map.graph[sl->player.x + x][sl->player.y + y] == 'e' \
		|| sl->map.graph[sl->player.x + x][sl->player.y + y] == '1')
		return ;
	old_pos.x = sl->player.x;
	old_pos.y = sl->player.y;
	sl->player.x += x;
	sl->player.y += y;
	if (sl->map.graph[sl->player.x][sl->player.y] == 'c')
		sl->characs.collectibles --;
	sl->map.graph[sl->player.x][sl->player.y] = 'p';
	sl->map.graph[old_pos.x][old_pos.y] = '.';
	call_last(sl, x, y);
}

int	key_hook(int kc, t_sl *sl)
{
	if (kc == KEY_ESC)
		return (close_window(sl));
	if (sl->player.x <= 0 || sl->player.y <= 0 || \
		sl->player.x >= sl->map.height || sl->player.y >= sl->map.width)
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
