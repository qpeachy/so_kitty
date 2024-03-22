/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:21:42 by mapale            #+#    #+#             */
/*   Updated: 2024/02/23 18:52:46 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strdup(char *s)
{
	char	*new;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s) + 1;
	if (!s)
		return (NULL);
	new = (char *)malloc(sizeof(char) * size);
	if (!new)
		return (s = NULL, NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strdup_s(char *s, int start, int stop)
{
	char	*new;
	int		size;
	int		i;

	i = 0;
	size = (stop - start) + 1;
	if (!s)
		return (NULL);
	new = (char *)malloc(sizeof(char) * size);
	if (!new)
	{
		free(s);
		return (s = NULL, NULL);
	}
	while (start < stop)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	free(s);
	new[i] = '\0';
	return (new);
}
