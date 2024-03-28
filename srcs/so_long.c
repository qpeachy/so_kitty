/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:50:52 by mapale            #+#    #+#             */
/*   Updated: 2024/03/28 17:42:16 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pre_game(t_sl *sl, char **m)
{
	if (!pre_check_map(m, sl))
		return(EXIT_FAILURE);
	sl->win.height = sl->map.height * 64;
	sl->win.width = (sl->map.width * 64);
	sl->win.mlx = mlx_init();
	if (!sl->win.mlx)
		return (EXIT_FAILURE);
	if (sl->win.height > 800)
		sl->win.height = 800;
	if (sl->win.width > 700)
		sl->win.width = 700;
	//printf("\n%d %d\n", sl->win.height, sl->win.width);
	sl->win.window = mlx_new_window(sl->win.mlx, sl->win.width, sl->win.height, "What's up baby girl?");
	if (!sl->win.window)
		return (free(sl->win.mlx), EXIT_FAILURE);
	sl->win.renderer.img = mlx_new_image(sl->win.mlx, sl->win.width, sl->win.height);
	sl->win.renderer.addr = mlx_get_data_addr(sl->win.renderer.img,
							&(sl->win.renderer.bits_per_pixel),
							&(sl->win.renderer.line_length), &(sl->win.renderer.endian));
	load_all(sl);
	sl->player.current_state = S_FOWARD;
	return (1);
}

void init_move(t_sl *sl)
{
	int	i;

	i = 16;
	while (sl->move.move / 10 == 0)
		sl->move.str[i--] = (sl->move.move % 10) + '0';
	sl->move.str[i] = (sl->move.move % 10) + '0';
}

int	main(int ac, char **av)
{
	t_sl sl;

	if (ac != 2)
		return (EXIT_SUCCESS);
	if (ft_strncmp(".ber", av[1]+(ft_strlen(av[1]) - 4), 3) != 0)
		return (error(&sl, "Error\nInvalid map extension\n"));
	sl.map.height = hm_line(av[1]);
	sl.map.graph = get_map(av[1], &sl);
	if (!sl.map.graph)
		return (0);
	if (!pre_game(&sl, sl.map.graph))
		return (free_map(&sl), EXIT_FAILURE);
	mapping(sl.map.graph, &sl);
	sl.move.move = 0;
	mlx_hook(sl.win.window, 17, 1L << 0, close_window, &sl);
	init_move(&sl);
	mlx_string_put((sl.win.mlx), (sl.win.window), 10, 10, 0, sl.move.str);
	mlx_key_hook(sl.win.window, key_hook, &sl);
	mlx_loop(sl.win.mlx);
}
