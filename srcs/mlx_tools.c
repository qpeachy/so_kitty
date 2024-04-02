/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:40:12 by mapale            #+#    #+#             */
/*   Updated: 2024/04/02 15:30:34 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_pixel(t_img *img, int x, int y)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	return (((int *)img->addr)[y * (img->line_length >> 2) + x]);
}

int	new_img(t_sl *sl, t_img *img, int w, int h)
{
	img->img = mlx_new_image(sl->win.mlx, w, h);
	img->height = h;
	img->width = w;
	if (!img->img)
		error(sl, ERR_IMG);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		error(sl, ERR_IMG);
	return (0);
}

int	load_img(t_sl *sl, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(sl->win.mlx, path, &(img->width),
			&(img->height));
	if (!img->img)
		error(sl, ERR_IMG);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		error(sl, ERR_TXT);
	return (0);
}

int	destroy_img(t_sl *sl, t_img *img)
{
	if (img->img)
		mlx_destroy_image(sl->win.mlx, img->img);
	return (0);
}

int	destroy_all_image(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 6)
		destroy_img(sl, &(sl->map.textures[i++]));
	while (j < 16)
		destroy_img(sl, &(sl->player.pos[j++]));
	return (0);
}
