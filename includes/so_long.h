/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:32:27 by mapale            #+#    #+#             */
/*   Updated: 2024/03/25 11:44:57 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include "../mlx/mlx.h"
# include "structs.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# define ERR_IMG "Error\nIssues with the mlx while creatinr..."
# define ERR_TXT "Error\nBlablablabla..."

# define WIN_X 1000
# define WIN_Y 700

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

/* utils */
int	ft_strlen(char *s);
void	ft_putstr(char *s);
int	error (t_sl *sl, char *message);
void	free_all(char **t);
int	hm_line(char *path);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

/* GetNextLine */
char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
char	*ft_offset(char *s, int end);
char	*ft_fu_strjoin(char *src, char *dst);
char	*ft_strdup(char *s);
char	*ft_strdup_s(char *s, int start, int stop);

/*Parsing*/
int	pre_check_map(char **m, t_sl *sl);
char	**get_map(char *path, t_sl *sl);
int	is_it_closed(char *line);
int	valid_char(char c, t_sl *sl);
int	check_line(char *line, t_sl *sl);
int	is_map_valid(char **map, t_sl *sl);

/*Doable*/
int	pre_doable(t_sl *sl, char **m);

/*mlx_tools*/
int	new_img(t_sl *sl, t_img *img, int w, int h);
int	load_img(t_sl *sl, char *path, t_img *img);
int	get_pixel(t_img *img, int x, int y);
int	close_window(t_sl *sl);

/*KeyHook*/
int	key_hook(int kc, t_sl *sl);

/* Display tools */
void	put_img_to_img(t_img *dst, t_img *src, int x, int y);
void	pixel_put(t_img *data, int x, int y, int color);
void	mapping(char **m, t_sl *sl);
void	put_in_camera(t_sl *sl);
t_img	*which_tile(char type, t_sl *sl);

/* set_textures */
void	load_all(t_sl *sl);

/* Animation */
void	in_hook_mapping(char **m, t_sl *sl, t_img *img);
void	up(char **map, t_sl *sl);
void	down(char **map, t_sl *sl);
void	left(char **map, t_sl *sl);
void	right(char **map, t_sl *sl);


/*A REMOVE*/
# include <stdio.h>
void	print_arr(char **s, t_sl *sl);
void	print_array(int *a, int size);
#endif