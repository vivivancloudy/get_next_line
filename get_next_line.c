/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:03:06 by thdinh            #+#    #+#             */
/*   Updated: 2025/02/12 15:14:13 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **buffer)
{
	char	*line;
	char	*newline;
	char	*tmp;
	size_t	len;

	if (!*buffer || **buffer == '\0')
		return (NULL);
	newline = ft_strchr(*buffer, '\n');
	if (newline)
		len = (size_t)(newline - *buffer + 1);
	else
		len = ft_strlen(*buffer);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *buffer, len);
	line[len] = '\0';
	if (newline)
		tmp = ft_strdup(newline + 1);
	else
		tmp = NULL;
	free(*buffer);
	*buffer = tmp;
	return (line);
}

static char	*read_and_store(int fd, char *buffer)
{
	char	*temp_buf;
	ssize_t	bytes_read;

	temp_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			temp_buf[bytes_read] = '\0';
			buffer = ft_strjoin(buffer, temp_buf);
			if (!buffer)
				break ;
		}
	}
	free(temp_buf);
	if (bytes_read < 0)
		return (NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_store(fd, buffer);
	if (!buffer || *buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (get_line(&buffer));
}
