/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:59:28 by mapale            #+#    #+#             */
/*   Updated: 2024/02/23 18:50:37 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_fu_strjoin(char *src, char *dst)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!src)
		return (ft_strdup(dst));
	if (!dst)
		return (ft_strdup(src));
	ret = (char *)malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(dst) + 1));
	if (!ret)
		return (free(dst), src = NULL, NULL);
	while (dst[i])
	{
		ret[i] = dst[i];
		i++;
	}
	while (src[++j])
		ret[i + j] = src[j];
	ret[i + j] = '\0';
	if (dst)
		free(dst);
	return (ret);
}

char	*ft_offset(char *s, int end)
{
	int		i;
	int		size;
	char	*tmp;

	tmp = s;
	size = ft_strlen(s);
	i = 0;
	while (end < size)
	{
		s[i] = tmp[end];
		i++;
		end++;
	}
	i--;
	while (s[++i])
		s[i] = '\0';
	return (s);
}

int	ft_gettillnewline(char *buf, char **string, int fd)
{
	int	char_read;

	char_read = -1;
	while (ft_strchr(buf, '\n') == -1 && char_read != 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
			return (-1);
		buf[char_read] = '\0';
		if (char_read == 0)
			return (1);
		*string = ft_fu_strjoin(buf, *string);
		if (!(*string))
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			tmp;
	char		*string;
	static char	buf[BUFFER_SIZE + 1];

	if (fd == -1 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (buf[0] = '\0', NULL);
	string = NULL;
	if (buf[0] != '\0')
	{
		string = ft_fu_strjoin(buf, string);
		if (!string)
			return (NULL);
	}
	tmp = ft_gettillnewline(buf, &string, fd);
	if (tmp == -1)
		return (NULL);
	else if (tmp == 1)
		return (string);
	string = ft_strdup_s(string, 0, ft_strchr(string, '\n') + 1);
	return (ft_offset(buf, ft_strchr(buf, '\n') + 1), string);
}
