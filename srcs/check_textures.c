/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:38:54 by mapale            #+#    #+#             */
/*   Updated: 2024/04/02 18:41:42 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_valid_textures5(t_sl *sl)
{
	int	tmpfd;

	(void)sl;
	tmpfd = open("textures/dead_kitty3.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/dead_kitty2.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/dead_kitty1.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	return (0);
}

static int	check_valid_textures4(t_sl *sl)
{
	int	tmpfd;

	tmpfd = open("textures/rightfoot_foward.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/rightfoot_left.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/rightfoot_right.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/dead_kitty4.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	return (check_valid_textures5(sl));
}

static int	check_valid_textures3(t_sl *sl)
{
	int	tmpfd;

	tmpfd = open("textures/leftfoot_back.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/leftfoot_foward.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/leftfoot_left.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/leftfoot_right.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/rightfoot_back.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	return (check_valid_textures4(sl));
}

static int	check_valid_textures2(t_sl *sl)
{
	int	tmpfd;

	tmpfd = open("textures/fake_coin.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/standby_back.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/standby_foward.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/standby_left.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/standby_right.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	return (check_valid_textures3(sl));
}

int	check_valid_textures(t_sl *sl)
{
	int	tmpfd;

	tmpfd = open("textures/grass.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close (tmpfd);
	tmpfd = open("textures/wall.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/coin.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/test1.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	tmpfd = open("textures/test2.xpm", O_RDONLY);
	if (tmpfd == -1)
		return (1);
	close(tmpfd);
	return (check_valid_textures2(sl));
}
