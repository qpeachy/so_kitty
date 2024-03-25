/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:36:32 by mapale            #+#    #+#             */
/*   Updated: 2024/03/25 11:50:03 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
} t_player;

typedef struct	s_charaters {
	int	collectibles;
	int	map_exit;
	int	player;
}	t_charac;

typedef struct	s_img {
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

typedef struct s_map {
	int	x;
	int	y;
	int	width;
	int	height;
	int	tile_w;
	char **graph;
	t_img	map;
	t_img textures[5];
}	t_map;

typedef struct	s_mob
{
	int	x;
	int	y;
	int direction;
	int width;
	int height;
	t_img	pos[12];
	int	current_state;
}	t_mob;

typedef struct vecteur{
	int	x;
	int	y;
} t_vect;

typedef struct s_sl
{
	t_mob	exit;
	t_win	win;
	t_map	map;
	t_mob	player;
	t_charac characs;
}	t_sl;

enum textures
{
	GRASS,
	WALL,
	COIN,
	EXIT_BEFORE,
	EXIT_AFTER,
	FAUX,
};

#endif