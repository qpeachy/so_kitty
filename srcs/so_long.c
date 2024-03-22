/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:50:52 by mapale            #+#    #+#             */
/*   Updated: 2024/03/22 15:58:27 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	((int *)data->addr)[y * (data->line_length >> 2) + x] = color;
}
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (++i < n + 1)
		((char *) s)[i - 1] = '\0';
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
		return(&(sl->player.current));
	return (NULL);
}

void	put_img_to_img(t_img *dst, t_img *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	/* printf("src w:%d h:%d | dst w:%d h:%d\n", src->width, src->height, dst->width, dst->height);
	printf("x: %d y:%d \n", x, y); */
	while (i + x < dst->width && i < src->width)
	{
		j = 0;
		while (y + j < dst->height && j < src->height)
		{
			/* printf("(i, j) (%d, %d)\n", i, j);
			printf("src w: %d, h: %d\n", src->width, src->height);
			printf("(i+x, j+y) (%d, %d)\n", i+x, j+y);
			printf("dst w: %d, h: %d\n", dst->width, dst->height); */
			//printf("get pixel = %d\n", get_pixel(src, i, j));
			if (get_pixel(src, i, j) != 306687)
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
			if (m[sl->map.x][sl->map.y] == 'p')
				put_img_to_img(&(sl->map.map), &(sl->map.textures[0]), sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
			put_img_to_img(&(sl->map.map), which_tile(m[sl->map.x][sl->map.y], sl), sl->map.y * sl->map.tile_w, sl->map.x * sl->map.tile_w);
			sl->map.y++;
		}
		sl->map.x++;
	}
	put_in_camera(sl);
}

int	pre_game(t_sl *sl, char **m)
{
	if (!pre_check_map(m, sl))
		return(EXIT_FAILURE);
	sl->win.mlx = mlx_init();
	if (!sl->win.mlx)
		return (EXIT_FAILURE);
	sl->win.window = mlx_new_window(sl->win.mlx, WIN_X, WIN_Y, "What's up bay girl?");
	if (!sl->win.window)
		return (free(sl->win.mlx), EXIT_FAILURE);
	sl->win.renderer.img = mlx_new_image(sl->win.mlx, WIN_X, WIN_Y);
	sl->win.renderer.addr = mlx_get_data_addr(sl->win.renderer.img,
							&(sl->win.renderer.bits_per_pixel),
							&(sl->win.renderer.line_length), &(sl->win.renderer.endian));
	load_all(sl);
	sl->player.current = sl->player.pos[S_FOWARD];
	return (1);
}

int	main(int ac, char **av)
{
	t_sl sl;
	char **m;

	if (ac != 2)
		return (EXIT_SUCCESS);
	if (ft_strncmp(".ber", av[1]+(ft_strlen(av[1]) - 4), 3) != 0)
		return (ft_error(&sl, "Error\nInvalid map extension\n"));
	sl.map.height = hm_line(av[1]);
	m = get_map(av[1], &sl);
	if (!m)
		return (0);
	if (!pre_game(&sl, m))
		return (EXIT_FAILURE);
	mapping(m, &sl);
	sl.map.graph = m;
	mlx_hook(sl.win.window, 17, 1L << 0, close_window, &sl);
	mlx_key_hook(sl.win.window, key_hook, &sl);
	mlx_loop(sl.win.mlx);
	mlx_destroy_image(sl.win.mlx, sl.win.renderer.img);
	mlx_destroy_window(sl.win.mlx, sl.win.window);
	mlx_destroy_display(sl.win.mlx);
}
