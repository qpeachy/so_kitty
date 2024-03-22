/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:45:49 by mapale            #+#    #+#             */
/*   Updated: 2024/03/19 13:49:35 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!*s)
		return ;
	i = 0;
	while (s[i])
		write(2, s + (i++), 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	free_all(char **t)
{
	(void)t;
	//free char**
}

int	ft_error (t_sl *sl, char *message)
{
	(void)sl;
	ft_putstr(message);
 /* 	mlx_destroy_image(sl->win.mlx, sl->win.renderer.img);
	mlx_destroy_window(sl->win.mlx, sl->win.window);
	mlx_destroy_display(sl->win.mlx); */
	//ft_putstr(message);
	return (0);
}