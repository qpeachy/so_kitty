/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:50:52 by mapale            #+#    #+#             */
/*   Updated: 2024/04/03 18:12:13 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pre_game(t_sl *sl)
{
	if (check_valid_textures(sl))
		error(sl, "Error\n The textures are not texturing\n");
	sl->win.height = sl->map.height * 64;
	sl->win.width = sl->map.width * 64;
	sl->win.mlx = mlx_init();
	if (!sl->win.mlx)
		return (free(sl->move.nbr), EXIT_FAILURE);
	if (sl->win.height > 800)
		sl->win.height = 800;
	if (sl->win.width > 700)
		sl->win.width = 700;
	sl->win.window = mlx_new_window(sl->win.mlx, sl->win.width, \
		sl->win.height, "What's up baby girl?");
	if (!sl->win.window)
		return (free(sl->win.mlx), \
		free(sl->move.nbr), EXIT_FAILURE);
	sl->win.renderer.img = mlx_new_image(sl->win.mlx, \
		sl->win.width, sl->win.height);
	sl->win.renderer.addr = mlx_get_data_addr(sl->win.renderer.img,
			&(sl->win.renderer.bits_per_pixel),
			&(sl->win.renderer.line_length), &(sl->win.renderer.endian));
	sl->player.current_state = S_FOWARD;
	load_all(sl);
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

int	check_input(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (i <= 4)
		return (0);
	if (s[i - 1] == 'r' && s[i - 2] == 'e' && s[i - 3] == 'b' \
	&& s[i - 4] == '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_sl	sl;

	if (ac != 2)
		return (putstr_fd("Error\n Two arguments are allowed\n"), EXIT_FAILURE);
	if (!check_input(av[1]))
		return (putstr_fd("Error\nInvalid map extension\n"), EXIT_FAILURE);
	if (init_parameters(&sl, av))
		return (free_map(&sl), EXIT_FAILURE);
	if (!is_map_valid(sl.map.graph, &sl))
		return (EXIT_FAILURE);
	if (!pre_game(&sl))
		return (free_map(&sl), EXIT_FAILURE);
	mapping(sl.map.graph, &sl);
	mlx_hook(sl.win.window, 17, 1L << 0, close_window, &sl);
	init_move(&sl);
	mlx_key_hook(sl.win.window, key_hook, &sl);
	mlx_loop(sl.win.mlx);
}
