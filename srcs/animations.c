/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:42:40 by mapale            #+#    #+#             */
/*   Updated: 2024/03/25 13:34:19 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				put_img_to_img(&(sl->map.map), &(sl->map.textures[GRASS]), sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
				put_img_to_img(&(sl->map.map), img, sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
			}
			else
			{
				put_img_to_img(&(sl->map.map), &(sl->map.textures[GRASS]), sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
				put_img_to_img(&(sl->map.map), which_tile(m[sl->map.x][sl->map.y], sl), sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
			}
			sl->map.y++;
		}
		sl->map.x++;
	}
	put_in_camera(sl);
}

void	up(char **map, t_sl *sl)
{
	in_hook_mapping(map, sl, &(sl->player.pos[R_BACK]));
	in_hook_mapping(map, sl, &(sl->player.pos[L_BACK]));
	in_hook_mapping(map, sl, &(sl->player.pos[S_BACK]));
}

void	down(char **map, t_sl *sl)
{
	in_hook_mapping(map, sl, &(sl->player.pos[R_FOWARD]));
	in_hook_mapping(map, sl, &(sl->player.pos[L_FOWARD]));
	in_hook_mapping(map, sl, &(sl->player.pos[S_FOWARD]));
}

void	left(char **map, t_sl *sl)
{
	in_hook_mapping(map, sl, &(sl->player.pos[R_LEFT]));
	in_hook_mapping(map, sl, &(sl->player.pos[L_LEFT]));
	in_hook_mapping(map, sl, &(sl->player.pos[S_LEFT]));
}

void	right(char **map, t_sl *sl)
{
	in_hook_mapping(map, sl, &(sl->player.pos[R_RIGHT]));
	in_hook_mapping(map, sl, &(sl->player.pos[L_RIGHT]));
	in_hook_mapping(map, sl, &(sl->player.pos[S_RIGHT]));
}