/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:36:32 by mapale            #+#    #+#             */
/*   Updated: 2024/04/02 16:40:51 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stddef.h>

typedef enum e_player
{
	S_BACK,
	S_FOWARD,
	S_LEFT,
	S_RIGHT,
	L_BACK,
	L_FOWARD,
	L_LEFT,
	L_RIGHT,
	R_BACK,
	R_FOWARD,
	R_LEFT,
	R_RIGHT,
	ONE_DEAD,
	TWO_DEAD,
	THREE_DEAD,
	FOUR_DEAD,
}	t_player;

typedef struct s_charaters
{
	int	collectibles;
	int	map_exit;
	int	player;
}	t_charac;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_win
{
	void	*mlx;
	void	*window;
	t_img	renderer;
	int		height;
	int		width;
}	t_win;

typedef struct s_map
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		tile_w;
	char	**graph;
	t_img	map;
	t_img	textures[6];
}	t_map;

typedef struct s_mob
{
	int		x;
	int		y;
	int		direction;
	int		width;
	int		height;
	t_img	pos[16];
	int		current_state;
}	t_mob;

typedef struct vecteur
{
	int	x;
	int	y;
}	t_vect;

typedef struct s_move
{
	unsigned int	move;
	char			*nbr;
}	t_move;

typedef struct s_sl
{
	t_move		move;
	t_win		win;
	t_map		map;
	t_mob		player;
	t_charac	characs;
}	t_sl;

typedef enum e_textures
{
	GRASS,
	WALL,
	COIN,
	EXIT_BEFORE,
	EXIT_AFTER,
	KILLER,
}	t_textures;

#endif