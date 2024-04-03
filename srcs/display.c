/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:45:20 by mapale            #+#    #+#             */
/*   Updated: 2024/04/03 14:09:10 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	center_window(t_sl *sl)
{
	if (sl->map.width * 64 > sl->win.height)
	{
		if ((sl->player.y * 64) >= sl->win.height * 0.5)
			sl->map.x = -((sl->player.y * 64) - (sl->win.height * 0.5));
		if (sl->map.x * -1 > (sl->map.width * 64) - sl->win.height)
			sl->map.x = (sl->map.width * -64) + sl->win.height;
	}
	if (sl->map.height * 64 > sl->win.width)
	{
		if ((sl->player.x * 64) >= sl->win.width * 0.5)
			sl->map.y = -((sl->player.x * 64) - (sl->win.width * 0.5));
		if (sl->map.y * -1 > (sl->map.height * 64) - sl->win.width)
			sl->map.y = (sl->map.height * -64) + sl->win.width;
	}
}

void	put_in_camera(t_sl *sl)
{
	if (sl->map.width * 64 == sl->win.width \
		&& sl->map.height * 64 == sl->win.height)
		mlx_put_image_to_window(sl->win.mlx, \
			sl->win.window, sl->map.map.img, 0, 0);
	else
	{
		center_window(sl);
		if (sl->map.y > 0 && sl->map.y < 64)
			sl->map.y = 0;
		if (sl->map.x > 0 && sl->map.x < 64)
			sl->map.x = 0;
		mlx_put_image_to_window(sl->win.mlx, sl->win.window, \
			sl->map.map.img, sl->map.x, sl->map.y);
		str_put(sl);
	}
}

void	mapping(char **m, t_sl *sl)
{
	new_img(sl, &sl->map.map, sl->map.width * sl->map.tile_w, \
		sl->map.height * sl->map.tile_w);
	sl->map.x = 0;
	while (sl->map.x < sl->map.height)
	{
		sl->map.y = 0;
		while (sl->map.y < sl->map.width - 1)
		{
			if (m[sl->map.x][sl->map.y] == '.')
				put_img_to_img(&(sl->map.map), &(sl->map.textures[GRASS]), \
					sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
			else
			{
				put_img_to_img(&(sl->map.map), &(sl->map.textures[GRASS]), \
					sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
				put_img_to_img(&(sl->map.map), \
					which_tile(m[sl->map.x][sl->map.y], sl), \
					sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
			}
			sl->map.y++;
		}
		sl->map.x++;
	}
	put_in_camera(sl);
}
