/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:45:49 by mapale            #+#    #+#             */
/*   Updated: 2024/04/03 18:10:43 by mapale           ###   ########.fr       */
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

void	putstr(char *s)
{
	int	i;

	if (!*s)
		return ;
	i = 0;
	while (s[i])
		write(1, s + (i++), 1);
}

char	transform(char c)
{
	if (c == '0')
		return ('.');
	else
		return (c + 32);
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
