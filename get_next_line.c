/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:52:29 by thdinh            #+#    #+#             */
/*   Updated: 2025/02/05 12:23:24 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_line(char **buffer)
{
    char *line;
    char *newline;
    size_t len;
    char    *tmp;

    if (!*buffer || **buffer == '\0')
        return (NULL);
    newline = ft_strchr(*buffer, '\n');
    if (newline)
        len = newline - *buffer + 1;
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

char    *get_next_line(int fd)
{
	static char	*buffer;
	char		tmp_buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    while (!ft_strchr(buffer, '\n') && (bytes_read = read(fd, tmp_buffer, BUFFER_SIZE)) > 0)
    {
		tmp_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, tmp_buffer);
		if (!buffer)
			return (NULL);
	}
	if (bytes_read < 0 || (bytes_read == 0 && (!buffer || *buffer == '\0')))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (get_line(&buffer));
}
