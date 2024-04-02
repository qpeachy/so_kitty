/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:25:15 by mapale            #+#    #+#             */
/*   Updated: 2024/04/02 17:08:03 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *)s;
	while (n > 0)
	{
		temp[n - 1] = '\0';
		n--;
	}
	s = temp;
}

void	str_put(t_sl *sl)
{
	mlx_string_put((sl->win.mlx), (sl->win.window), 10, 10, 0, "Moves :");
	mlx_string_put((sl->win.mlx), (sl->win.window), 65, 10, 0, sl->move.nbr);
}

char	transform(char c)
{
	if (c == '0')
		return ('.');
	else
		return (c + 32);
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
