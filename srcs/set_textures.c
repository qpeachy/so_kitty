/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:53:46 by mapale            #+#    #+#             */
/*   Updated: 2024/03/25 13:55:32 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_imgs_in_texture(t_sl *sl)
{
	load_img(sl, "textures/grass.xpm", &(sl->map.textures[GRASS]));
	load_img(sl, "textures/wall.xpm", &(sl->map.textures[WALL]));
	load_img(sl, "textures/coin.xpm", &(sl->map.textures[COIN]));
	load_img(sl, "textures/test1.xpm", &(sl->map.textures[EXIT_BEFORE]));
	load_img(sl, "textures/test2.xpm", &(sl->map.textures[EXIT_AFTER]));
}

void	load_imgs_of_player(t_sl *sl)
{
	load_img(sl, "textures/standby_back.xpm", &(sl->player.pos[S_BACK]));
	load_img(sl, "textures/standby_foward.xpm", &(sl->player.pos[S_FOWARD]));
	load_img(sl, "textures/standby_left.xpm", &(sl->player.pos[S_LEFT]));
	load_img(sl, "textures/standby_right.xpm", &(sl->player.pos[S_RIGHT]));
	load_img(sl, "textures/leftfoot_back.xpm", &(sl->player.pos[L_BACK]));
	load_img(sl, "textures/leftfoot_foward.xpm", &(sl->player.pos[L_FOWARD]));
	load_img(sl, "textures/leftfoot_left.xpm", &(sl->player.pos[L_LEFT]));
	load_img(sl, "textures/leftfoot_right.xpm", &(sl->player.pos[L_RIGHT]));
	load_img(sl, "textures/rightfoot_back.xpm", &(sl->player.pos[R_BACK]));
	load_img(sl, "textures/rightfoot_foward.xpm", &(sl->player.pos[R_FOWARD]));
	load_img(sl, "textures/rightfoot_left.xpm", &(sl->player.pos[R_LEFT]));
	load_img(sl, "textures/rightfoot_right.xpm", &(sl->player.pos[R_RIGHT]));
}
void	load_all(t_sl *sl)
{
	load_imgs_in_texture(sl);
	load_imgs_of_player(sl);
}