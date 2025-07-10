/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:30:09 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/24 16:53:07 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>

char	*ft_fill_sta(char *sta, int fd)
{
	ssize_t	endbuf;
	char	*buf;
	char	*tmp;

	endbuf = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (free(sta), NULL);
	while (ft_strchr(sta, '\n') == 0 && endbuf != 0)
	{
		endbuf = read(fd, buf, BUFFER_SIZE);
		if (endbuf < 0)
			return (free(buf), free(sta), NULL);
		buf[endbuf] = '\0';
		tmp = ft_strjoin(sta, buf);
		if (!tmp)
			return (free(buf), free(sta), NULL);
		free(sta);
		sta = tmp;
	}
	free(buf);
	return (sta);
}

char	*ft_fill_line(char *sta)
{
	char	*line;
	int		i;

	i = 0;
	if (!sta || !sta[0])
		return (NULL);
	while (sta[i] != '\n' && sta[i])
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
		i++;
	line[i] = '\0';
	return (line);
}

char	*ft_new_sta(char *sta)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (sta[i] && sta[i] != '\n')
		i++;
	if (sta[i] == '\0')
		return (free(sta), sta = NULL, NULL);
	i++;
	if (!sta)
		return (free(sta), sta = NULL, NULL);
	if (!sta[i])
		return (free(sta), sta = NULL, NULL);
	new = malloc(sizeof(char) * (ft_strlen(&sta[i]) + 1));
	if (!new)
		return (free(sta), sta = NULL, NULL);
	while (sta[i])
		new[j++] = sta[i++];
	new[j] = '\0';
	free(sta);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*sta[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(sta[fd]);
		sta[fd] = NULL;
		return (NULL);
	}
	sta[fd] = ft_fill_sta(sta[fd], fd);
	if (!sta[fd])
		return (NULL);
	line = ft_fill_line(sta[fd]);
	if (line == NULL)
	{
		free(sta[fd]);
		sta[fd] = NULL;
		return (NULL);
	}
	sta[fd] = ft_new_sta(sta[fd]);
	return (line);
}
