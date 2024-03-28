/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:42:40 by mapale            #+#    #+#             */
/*   Updated: 2024/03/28 17:38:38 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(char **map, t_sl *sl, int status)
{
	if (status == 1)
	{
		in_hook_mapping(map, sl, &(sl->player.pos[R_BACK]));
		wait();
		in_hook_mapping(map, sl, &(sl->player.pos[S_BACK]));
		wait();
	}
	else
	{
		in_hook_mapping(map, sl, &(sl->player.pos[L_BACK]));
		wait();
		in_hook_mapping(map, sl, &(sl->player.pos[S_BACK]));
		wait();
	}
}

void	down(char **map, t_sl *sl, int status)
{
	if (status == 1)
	{
		in_hook_mapping(map, sl, &(sl->player.pos[R_FOWARD]));
		wait();
		in_hook_mapping(map, sl, &(sl->player.pos[S_FOWARD]));
		wait();
	}
	else
	{
		in_hook_mapping(map, sl, &(sl->player.pos[L_FOWARD]));
		wait();
		in_hook_mapping(map, sl, &(sl->player.pos[S_FOWARD]));
		wait();
	}
}

void	left(char **map, t_sl *sl, int status)
{
	if (status == 1)
	{
		in_hook_mapping(map, sl, &(sl->player.pos[R_LEFT]));
		wait();
		in_hook_mapping(map, sl, &(sl->player.pos[S_LEFT]));
		wait();
	}
	else
	{
		in_hook_mapping(map, sl, &(sl->player.pos[L_LEFT]));
		wait();
		in_hook_mapping(map, sl, &(sl->player.pos[S_LEFT]));
		wait();
	}
}

void	right(char **map, t_sl *sl, int status)
{
	if (status == 1)
	{
		in_hook_mapping(map, sl, &(sl->player.pos[R_RIGHT]));
		wait();
		in_hook_mapping(map, sl, &(sl->player.pos[S_RIGHT]));
		wait();
	}
	else
	{
		in_hook_mapping(map, sl, &(sl->player.pos[L_RIGHT]));
		wait();
		in_hook_mapping(map, sl, &(sl->player.pos[S_RIGHT]));
		wait();
	}
}

void	kitty_died(t_sl *sl)
{
	in_hook_mapping(sl->map.graph, sl, &(sl->player.pos[ONE_DEAD]));
	wait();
	wait();
	in_hook_mapping(sl->map.graph, sl, &(sl->player.pos[TWO_DEAD]));
	wait();
	wait();
	in_hook_mapping(sl->map.graph, sl, &(sl->player.pos[THREE_DEAD]));
	wait();
	wait();
	in_hook_mapping(sl->map.graph, sl, &(sl->player.pos[FOUR_DEAD]));
	wait();
	wait();
	ft_putstr("AURR NAUR YOU DIIIEDDD\n");
	close_window(sl);
}