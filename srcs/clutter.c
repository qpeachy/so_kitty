                                                                                                    /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clutter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:02:38 by mapale            #+#    #+#             */
/*   Updated: 2024/03/04 15:56:22 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void img_to_wind(t_win *in_win,t_img img, char *path, int x, int y)
{
	//printf("x = %d | y = %d\n", x, y);
	img.img = mlx_xpm_file_to_image(in_win->mlx, path, &img.width, &img.height);
	if (!img.img)
		return ;
	img.addr = mlx_get_data_addr(img.img,
							&img.bits_per_pixel,
							&img.line_length, &img.endian);
	mlx_put_image_to_window(in_win->mlx, in_win->window, img.img, x * 64, y * 64);
	mlx_destroy_image(in_win->mlx, img.img);
}

void	img_to_map(t_img *map, int x, int y)
{
	
}

void	load_images(char c, t_win *in_win, int x, int y)
{
	/*char	*path1;
	char	*path2;
	char	*path3;
	char	*path4;

	t_map	map;

	path1 = "textures/grass.xpm";
	path2 = "textures/wall.xpm";
	path3 = "textures/coin.xpm";
	path4 = "textures/door_closed.xpm";
	if (c == '0')
		img_to_wind(in_win, map.grass, path1, x, y);
	if (c == '1')
		img_to_wind(in_win, map.wall, path2, x, y);
	if (c == 'C')
		img_to_wind(in_win, map.coin, path3, x, y);
	if (c == 'E')
		img_to_wind(in_win, map.door_c, path4, x, y);
	if (c == 'P')
		img_to_wind(in_win, map.wall, path2, x, y); */
}

void	mapping(char *path, t_win *in_win)
{
	t_img	map;
	char	*m;
	int		fd;
	int		x;
	int		y;

	fd = open(path, O_RDONLY);
	m = get_next_line(fd);
	x = 0;
	while (m)
	{
		y = 0;
		while(m[y] != '\n')
		{
			load_images(m[y], in_win, x, y);
			y++;
		}
		free (m);
		m = get_next_line(fd);
		x++;
	}
	//img_to_wind();
}

int	main(int ac, char **av)
{
	t_win	in_win;

	if (ac != 2)
		return (EXIT_SUCCESS);
/* 	if (!ft_valid_input(av[1]))
		return (ft_putstr("Error\nInvalid map extension\n")); */
	/*check if argv[2] ends properly with "".ber"*/
	in_win.mlx = mlx_init();
	if (!in_win.mlx)
		return (EXIT_FAILURE);
	in_win.window = mlx_new_window(in_win.mlx, 1020, 1080, "What's up bay girl?");
	if (!in_win.window)
		return (EXIT_FAILURE);
	in_win.renderer.img = mlx_new_image(in_win.mlx, 1020, 1080);
	in_win.renderer.addr = mlx_get_data_addr(in_win.renderer.img,
							&in_win.renderer.bits_per_pixel,
							&in_win.renderer.line_length, &in_win.renderer.endian);
	mapping(av[1], &in_win);
	//move_it(&in_win);
	//mlx_key_hook(in_win.window, key_hook, &in_win);
	mlx_loop(in_win.mlx);
}

/* void	move_it(t_win *in_win)
{
	load_images(in_win);
	int y, x;
	x = 0;
	while (x++ < 100)
	{
		y = 0;
		while (y++ < 100)
			pixel_put(&in_win->renderer,800 + x, 63 + y, 0xFFFF0000);
	}
	mlx_put_image_to_window(in_win->mlx, in_win->window, in_win->renderer.img, in_win->horizontal, in_win->vertical);
} */

/* int	key_hook(int kc, t_win *in_win)
{
	if (kc == 65361)//left
	{
		in_win->horizontal--;
		move_it(in_win);
	}
	if (kc == 65362)//up
	{
		in_win->vertical--;
		move_it(in_win);
	}
	if (kc == 65363)//right
	{
		in_win->horizontal++;
		move_it(in_win);
	}
	if (kc == 65364)//down
	{
		in_win->vertical++;
		move_it(in_win);
	}
	////printf("keycode = %d\n", kc);
	return (0);
} */