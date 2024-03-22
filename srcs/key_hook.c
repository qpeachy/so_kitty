/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:03:28 by mapale            #+#    #+#             */
/*   Updated: 2024/03/22 17:32:43 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



/* t_img *which_change(t_sl *sl)
{
	
} */

void	in_hook_mapping(char **m, t_sl *sl, t_img *img)
{
	sl->map.tile_w = 64;
	new_img(sl, &sl->map.map, sl->map.width * sl->map.tile_w, sl->map.height * sl->map.tile_w);
	sl->map.x = 0;
	while (sl->map.x < sl->map.height)
	{
		sl->map.y = 0;
		while(sl->map.y < sl->map.width - 1)
		{
			if (m[sl->map.x][sl->map.y] == 'p')
			{
				put_img_to_img(&(sl->map.map), &(sl->map.textures[0]), sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
				put_img_to_img(&(sl->map.map), img, sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
			}
			else
				put_img_to_img(&(sl->map.map), which_tile(m[sl->map.x][sl->map.y], sl), sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
			sl->map.y++;
		}
		sl->map.x++;
	}
	put_in_camera(sl);
}


void	move_character(t_sl *sl, t_img *img, int x, int y)
{
	t_vect old_pos;

	old_pos.x = sl->player.x;
	old_pos.y = sl->player.y;
	if (sl->map.graph[sl->player.x + x][sl->player.y + y] == '1')
		return ;
	sl->player.x += x;
	sl->player.y += y;
	if (sl->map.graph[sl->player.x][sl->player.y] == 'c')
		sl->characs.collectibles --;
	sl->map.graph[sl->player.x][sl->player.y] = 'p';
	sl->map.graph[old_pos.x][old_pos.y] = '.';
	in_hook_mapping(sl->map.graph, sl, img);
}

int	key_hook(int kc, t_sl *sl)
{
	if (sl->player.x <= 0 || sl->player.y <= 0 || sl->player.x >= sl->map.height|| sl->player.y >= sl->map.width)
		return (0);
	if (kc == KEY_UP)
		move_character(sl, &(sl->player.pos[R_BACK]), -1, 0);
	if (kc == KEY_DOWN)
		move_character(sl, &(sl->player.pos[R_FOWARD]), 1, 0);
	if (kc == KEY_LEFT)
		move_character(sl, &(sl->player.pos[R_RIGHT]), 0, -1);
	if (kc == KEY_RIGHT)
		move_character(sl, &(sl->player.pos[R_LEFT]), 0, 1);
	return (0);
}
