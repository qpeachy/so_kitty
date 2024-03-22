/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:40:12 by mapale            #+#    #+#             */
/*   Updated: 2024/03/19 10:42:31 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_pixel(t_img *img, int x, int y)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	//print_array((int *)img->addr, 5);
	return (((int *)img->addr)[y * (img->line_length >> 2) + x]);
}

int	new_img(t_sl *sl, t_img *img, int w, int h)
{
	img->img = mlx_new_image(sl->win.mlx, w, h);
	img->height = h;
	img->width = w;
	if (!img->img)
		ft_error(sl, ERR_IMG);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		ft_error(sl, ERR_IMG);
	return (0);
}

int	load_img(t_sl *sl, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(sl->win.mlx, path, &(img->width),
			&(img->height));
	if (!img->img)
		ft_error(sl, ERR_IMG);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		ft_error(sl, ERR_TXT);
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

	i = 0;
	while (i < 5)
		destroy_img(sl, &(sl->map.textures[i++]));
	return (0);
}

int	close_window(t_sl *sl)
{
	//destroy_all_image(sl);
	destroy_img(sl, &(sl->map.map));
	destroy_img(sl, &(sl->win.renderer));
	if (sl->map.map.img)
		free(sl->map.map.img);
	if (sl->win.renderer.img)
		mlx_destroy_window(sl->win.mlx, sl->win.renderer.addr);
	if (sl->win.mlx)
	{
		mlx_destroy_display(sl->win.mlx);
		free(sl->win.mlx);
	}
	exit(0);
	return (0);
}
