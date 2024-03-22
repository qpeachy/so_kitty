/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:03:28 by mapale            #+#    #+#             */
/*   Updated: 2024/03/22 13:03:41 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	in_hook(t_sl *sl, t_img *img)
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
	(void)y;
	if (sl->map.graph[sl->player.x][sl->player.y] == '1')
		return ;
	if (sl->map.graph[sl->player.x][sl->player.y] == 'c')
		sl->characs.collectibles --;
	sl->map.graph[sl->player.x][sl->player.y] = 'p';
	sl->map.graph[x][y] = '.';
	in_hook_mapping(sl->map.graph, sl, img);
}

/* void	move_character_y(t_sl *sl, t_img *img, int x, int y)
{
	(void)x;
	if (sl->map.graph[sl->player.x][sl->player.y] == '1')
		return ;
	sl->map.graph[sl->player.x][sl->player.y] = 'p';
	sl->map.graph[x][y] = '.';
	in_hook_mapping(sl->map.graph, sl, img);
} */

int	key_hook(int kc, t_sl *sl)
{
	int p_x;
	int p_y;

	print_arr(sl->map.graph, sl);
	if (kc == KEY_UP)
	{
		if (sl->player.x <= 0 || sl->player.y <= 0 || sl->player.x >= sl->map.height|| sl->player.y >= sl->map.width)
			return (0);
		printf("\n(x,y)(%d,%d)\n", sl->player.y, sl->player.x);
		p_x = sl->player.x;
		p_y = sl->player.y;
		if (sl->map.graph[sl->player.x - 1][sl->player.y] == '1')
			return (0);
		sl->player.x--;
		printf("\n(x,y)(%d,%d)\n", sl->player.y, sl->player.x);
		move_character(sl, &(sl->player.pos[R_BACK]), p_x, p_y);
	}
	if (kc == KEY_DOWN)
	{
		if (sl->player.x <= 0 || sl->player.y <= 0 || sl->player.x >= sl->map.height|| sl->player.y >= sl->map.width)
			return (0);
		printf("\n(x,y)(%d,%d)\n", sl->player.y, sl->player.x);
		p_x = sl->player.x;
		p_y = sl->player.y;
		if (sl->map.graph[sl->player.x + 1][sl->player.y] == '1')
			return (0);
		sl->player.x++;
		printf("\n(x,y)(%d,%d)\n", sl->player.y, sl->player.x);
		move_character(sl, &(sl->player.pos[R_FOWARD]), p_x, p_y);
	}
	if (kc == KEY_LEFT)
	{
		if (sl->player.x <= 0 || sl->player.y <= 0 || sl->player.x >= sl->map.height|| sl->player.y >= sl->map.width)
			return (0);
		printf("\n(x,y)(%d,%d)\n", sl->player.y, sl->player.x);
		p_x = sl->player.x;
		p_y = sl->player.y;
		if (sl->map.graph[sl->player.x][sl->player.y - 1] == '1')
			return (0);
		sl->player.y--;
		printf("\n(x,y)(%d,%d)\n", sl->player.y, sl->player.x);
		move_character(sl, &(sl->player.pos[R_RIGHT]), p_x, p_y);
	}
	if (kc == KEY_RIGHT)
	{
		if (sl->player.x <= 0 || sl->player.y <= 0 || sl->player.x >= sl->map.height|| sl->player.y >= sl->map.width)
			return (0);
		printf("\n(x,y)(%d,%d)\n", sl->player.y, sl->player.x);
		p_x = sl->player.x;
		p_y = sl->player.y;
		if (sl->map.graph[sl->player.x][sl->player.y + 1] == '1')
			return (0);
		sl->player.y++;
		printf("\n(x,y)(%d,%d)\n", sl->player.y, sl->player.x);
		move_character(sl, &(sl->player.pos[R_LEFT]), p_x, p_y);
	}
	printf("keycode = %d\n", kc);
	return (0);
}
