/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doable.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:46:12 by mapale            #+#    #+#             */
/*   Updated: 2024/03/19 13:57:43 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_in_s(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		//printf("%c\n",s[i]);
		if (c == '\n')
			i++;
		if (c == '\0' || s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	transform(char c)
{
	if (c == '0')
		return ('.');
	else
		return(c + 32);
}

int	is_it_flooded(char **m, t_sl *sl)
{
	int	x;
	int	y;

	x = 0;
	//print_arr(m, sl);
	while (x < sl->map.height)
	{
		y = 0;
		while(y < sl->map.width)
		{
			//printf("\n%c is_in = %d\n",  m[x][y], is_in_s("1.pce", m[x][y]));
			if (!is_in_s("1.pce", m[x][y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	can_u_play(t_sl *sl, char **m, int x, int y)
{
	 if (x <= 0 || y <= 0 || x >= sl->map.height|| y >= sl->map.width)
		return (1);
	if (m[x][y] != '1' && (m[x][y] == 'P' || m[x][y] == 'C' || m[x][y] == 'E' || m[x][y] == '0'))
	{
		m[x][y] = transform(m[x][y]);
		can_u_play(sl, m, x + 1, y);
		can_u_play(sl, m, x - 1, y);
		can_u_play(sl, m, x, y + 1);
		can_u_play(sl, m, x, y - 1);
	}
	return (0);
}

int	last_check(t_sl *sl, char **m, int x, int y)
{
	can_u_play(sl, m, x, y);
	print_arr(m, sl);
	if (is_it_flooded(m, sl) == 1)
	{
		printf("\ni = %d\n", is_it_flooded(m, sl));
		return (ft_error(sl, "Error\nAre you trying to piss me off? Your map isn't even doable\n"));
	}
	return (1);
}

int	pre_doable(t_sl *sl, char **m)
{
	int		x;
	int		y;
	
	x = 0;
	while (x < sl->map.height)
	{
		y = 0;
		while(y < sl->map.width)
		{
			if (m[x][y] == 'P')
			{
				sl->player.x = x;
				sl->player.y = y;
				return (last_check(sl, m, x, y));
			}
			y++;
		}
		x++;
	}
	return (0);
}
