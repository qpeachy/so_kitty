/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:17:40 by mapale            #+#    #+#             */
/*   Updated: 2024/04/02 18:42:00 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	in_hook_mapping(char **m, t_sl *sl, t_img *img)
{
	if (sl->map.map.img)
		destroy_img(sl, &(sl->map.map));
	new_img(sl, &sl->map.map, sl->map.width * sl->map.tile_w, \
		sl->map.height * sl->map.tile_w);
	sl->map.x = 0;
	while (sl->map.x < sl->map.height)
	{
		sl->map.y = 0;
		while (sl->map.y < sl->map.width - 1)
		{
			put_img_to_img(&(sl->map.map), &(sl->map.textures[GRASS]), \
				sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
			if (m[sl->map.x][sl->map.y] == 'p')
				put_img_to_img(&(sl->map.map), img, sl->map.y * sl->map.tile_w, \
					sl->map.x * sl->map.tile_w);
			else
				put_img_to_img(&(sl->map.map), \
					which_tile(m[sl->map.x][sl->map.y], sl), \
					sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
			sl->map.y++;
		}
		sl->map.x++;
	}
	put_in_camera(sl);
}

void	wait(void)
{
	size_t	i;

	i = 1;
	while (i % 5000000 != 0)
		i++;
}
