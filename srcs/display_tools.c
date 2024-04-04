/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:48:34 by mapale            #+#    #+#             */
/*   Updated: 2024/04/03 18:09:03 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	((int *)data->addr)[y * (data->line_length >> 2) + x] = color;
}

t_img	*which_tile(char type, t_sl *sl)
{
	if (type == '.' || type == '0')
		return (&(sl->map.textures[GRASS]));
	else if (type == 'c')
		return (&(sl->map.textures[COIN]));
	else if (type == 'K')
		return (&(sl->map.textures[KILLER]));
	else if (type == 'e' && sl->characs.collectibles == 0)
		return (&(sl->map.textures[EXIT_AFTER]));
	else if (type == 'e')
		return (&(sl->map.textures[EXIT_BEFORE]));
	else if (type == 'p')
		return (&(sl->player.pos[S_FOWARD]));
	else
		return (&(sl->map.textures[WALL]));
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
			if (get_pixel(src, i, j) != 306687 && \
				get_pixel(src, i, j) != 14917035)
				pixel_put(dst, x + i, y + j, get_pixel(src, i, j));
			j++;
		}
		i++;
	}
}
