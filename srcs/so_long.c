/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:50:52 by mapale            #+#    #+#             */
/*   Updated: 2024/04/02 15:24:14 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pre_game(t_sl *sl, char **m)
{
	if (!is_map_valid(m, sl))
		return (EXIT_FAILURE);
	sl->win.height = sl->map.height * 64;
	sl->win.width = sl->map.width * 64;
	sl->win.mlx = mlx_init();
	if (!sl->win.mlx)
		return (EXIT_FAILURE);
	if (sl->win.height > 800)
		sl->win.height = 800;
	if (sl->win.width > 700)
		sl->win.width = 700;
	sl->win.window = mlx_new_window(sl->win.mlx, sl->win.width, \
		sl->win.height, "What's up baby girl?");
	if (!sl->win.window)
		return (free(sl->win.mlx), EXIT_FAILURE);
	sl->win.renderer.img = mlx_new_image(sl->win.mlx, \
		sl->win.width, sl->win.height);
	sl->win.renderer.addr = mlx_get_data_addr(sl->win.renderer.img,
			&(sl->win.renderer.bits_per_pixel),
			&(sl->win.renderer.line_length), &(sl->win.renderer.endian));
	load_all(sl);
	sl->player.current_state = S_FOWARD;
	return (1);
}

int	ft_strlen_c(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	d_size;

	i = 0;
	d_size = ft_strlen(dest);
	while (src[i])
	{
		dest[d_size + i] = src[i];
		i++;
	}
	dest[d_size + i] = '\0';
	return (ft_strlen_c(src) + d_size);
}

int	main(int ac, char **av)
{
	t_sl	sl;

	if (ac != 2)
		return (EXIT_SUCCESS);
	if (ft_strncmp(".ber", av[1] + (ft_strlen(av[1]) - 4), 3) != 0)
		return (error(&sl, "Error\nInvalid map extension\n"));
	if (init_parameters(&sl, av))
		return (free_map(&sl), EXIT_FAILURE);
	if (!pre_game(&sl, sl.map.graph))
		return (free_map(&sl), EXIT_FAILURE);
	mapping(sl.map.graph, &sl);
	mlx_hook(sl.win.window, 17, 1L << 0, close_window, &sl);
	init_move(&sl);
	mlx_key_hook(sl.win.window, key_hook, &sl);
	mlx_loop(sl.win.mlx);
}
