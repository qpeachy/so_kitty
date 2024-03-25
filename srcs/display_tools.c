/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:48:34 by mapale            #+#    #+#             */
/*   Updated: 2024/03/25 14:11:00 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	((int *)data->addr)[y * (data->line_length >> 2) + x] = color;
}
t_img	*which_tile(char type, t_sl *sl)
{
	if (type == '1')
		return(&(sl->map.textures[WALL]));
	if (type == '.')
		return(&(sl->map.textures[GRASS]));
	if (type == 'c')
		return(&(sl->map.textures[COIN]));
	if (type == 'e' && sl->characs.collectibles == 0)
		return(&(sl->map.textures[EXIT_AFTER]));
	if (type == 'e')
		return(&(sl->map.textures[EXIT_BEFORE]));
	if (type == 'p')
		return(&(sl->player.pos[S_FOWARD]));
	return (NULL);
}

void	put_img_to_img(t_img *dst, t_img *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i + x < dst->width && i < src->width)
	{
		j = 0;
		while (y + j < dst->height && j < src->height)
		{
			if (get_pixel(src, i, j) != 306687 && get_pixel(src, i, j) != 14917035)//#93DC55)
				pixel_put(dst, x + i, y + j, get_pixel(src, i, j));
			j++;
		}
		i++;
	}
}

void	put_in_camera(t_sl *sl)
{
	if (sl->map.width * 64 > WIN_X)
	{
		if ((sl->player.y * 64) >= WIN_X * 0.5)
			sl->map.x = -((sl->player.y * 64) - (WIN_X * 0.5));
		if (sl->map.x * -1 > (sl->map.width * 64) - WIN_X)
			sl->map.x = (sl->map.width * -64) + WIN_X;
	}
	if (sl->map.height * 64 > WIN_Y)
	{
		if ((sl->player.x * 64) >= WIN_Y * 0.5)
			sl->map.y = -((sl->player.x * 64) - (WIN_Y * 0.5));
		if (sl->map.y * -1 > (sl->map.height * 64) - WIN_Y)
			sl->map.y = (sl->map.height * -64) + WIN_Y;
	}
	mlx_put_image_to_window(sl->win.mlx, sl->win.window, sl->map.map.img, sl->map.x, sl->map.y);
}

void	mapping(char **m, t_sl *sl)
{
	sl->map.tile_w = 64;
	new_img(sl, &sl->map.map, sl->map.width * sl->map.tile_w, sl->map.height * sl->map.tile_w);
	sl->map.x = 0;
	while (sl->map.x < sl->map.height)
	{
		sl->map.y = 0;
		while(sl->map.y < sl->map.width - 1)
		{
			if (m[sl->map.x][sl->map.y] == '.')
				put_img_to_img(&(sl->map.map), &(sl->map.textures[GRASS]), sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
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
