/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:50:52 by mapale            #+#    #+#             */
/*   Updated: 2024/03/25 11:44:57 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	sl->player.current_state = S_FOWARD;
	return (1);
}

int	main(int ac, char **av)
{
	t_sl sl;
	char **m;

	if (ac != 2)
		return (EXIT_SUCCESS);
	if (ft_strncmp(".ber", av[1]+(ft_strlen(av[1]) - 4), 3) != 0)
		return (error(&sl, "Error\nInvalid map extension\n"));
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
