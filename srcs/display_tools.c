/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:48:34 by mapale            #+#    #+#             */
/*   Updated: 2024/04/02 15:36:14 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	((int *)data->addr)[y * (data->line_length >> 2) + x] = color;
}

t_img	*which_tile(char type, t_sl *sl)
{
	if (type == '1')
		return (&(sl->map.textures[WALL]));
	if (type == '.')
		return (&(sl->map.textures[GRASS]));
	if (type == 'c')
		return (&(sl->map.textures[COIN]));
	if (type == 'k')
		return (&(sl->map.textures[KILLER]));
	if (type == 'e' && sl->characs.collectibles == 0)
		return (&(sl->map.textures[EXIT_AFTER]));
	if (type == 'e')
		return (&(sl->map.textures[EXIT_BEFORE]));
	if (type == 'p')
		return (&(sl->player.pos[S_FOWARD]));
	return (NULL);
}

void	put_img_to_img(t_img *dst, t_img *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i + x < dst->width && i < src->width)
	{
		j = 0;
		while (y + j < dst->height && j < src->height)
		{
			if (get_pixel(src, i, j) != 306687 && \
				get_pixel(src, i, j) != 14917035)
				pixel_put(dst, x + i, y + j, get_pixel(src, i, j));
			j++;
		}
		i++;
	}
}

int	num_size(int n)
{
	int	cnt;

	cnt = 0;
	if (n < 10)
		return (1);
	else
	{
		while (n != 0)
		{
			cnt++;
			n /= 10;
		}
	}
	return (cnt);
}

void	init_move(t_sl *sl)
{
	int	i;
	int	tmp;

	i = num_size(sl->move.move) - 1;
	if (i == -1)
		i = 0;
	tmp = sl->move.move;
	ft_bzero(sl->move.nbr, 10);
	if (sl->move.move == 0)
		sl->move.nbr[0] = '0';
	else
	{
		while (tmp != 0)
		{
			sl->move.nbr[i] = (tmp % 10) + '0';
			tmp /= 10;
			i--;
		}
	}
	sl->move.nbr[num_size(sl->move.move)] = '\0';
}
