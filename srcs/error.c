/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:47:52 by mapale            #+#    #+#             */
/*   Updated: 2024/04/03 18:14:38 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putstr_fd(char *s)
{
	int	i;

	if (!*s)
		return ;
	i = 0;
	while (s[i])
		write(2, s + (i++), 1);
}

void	free_map(t_sl *sl)
{
	int	i;

	i = 0;
	if (sl->move.nbr)
		free(sl->move.nbr);
	while (i < sl->map.height && sl->map.graph[i])
		free(sl->map.graph[i++]);
	free(sl->map.graph);
}

int	close_window(t_sl *sl)
{
	free_map(sl);
	destroy_all_image(sl);
	destroy_img(sl, &(sl->map.map));
	destroy_img(sl, &(sl->win.renderer));
	if (sl->win.renderer.img)
		mlx_destroy_window(sl->win.mlx, sl->win.window);
	if (sl->win.mlx)
	{
		mlx_destroy_display(sl->win.mlx);
		free(sl->win.mlx);
	}
	exit(0);
	return (0);
}

int	error(t_sl *sl, char *message)
{
	(void)sl;
	free_map(sl);
	putstr_fd(message);
	exit(1);
	return (1);
}
