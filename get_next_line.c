/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:52:29 by thdinh            #+#    #+#             */
/*   Updated: 2025/02/04 18:02:54 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_line(char **buffer)
{
    char *line;
    char *newline;
    size_t len;
    char    *tmp;

    if (!buffer || !*buffer || **buffer == '\0')
        return (NULL);
    newline = ft_strchr(*buffer, '\n');
    if (newline)
        len = newline - *buffer + 1;
    else
        len = ft_strlen(*buffer);
    line = malloc(len + 1);
    if (!line)
        return (NULL);
    ft_strncpy(line, *buffer, len);
    line[len] = '\0';
    if (newline)
    {
        tmp = ft_strdup(newline + 1);
        if (!tmp)
            return (free(*buffer), *buffer = NULL, NULL);
        free(*buffer);
        *buffer = tmp;
    }
    else
    {
        free(*buffer);
        *buffer = NULL;
    }
    return (line);
}
char    *get_next_line(int fd)
{
    static char *buffer;
    char        tmp_buffer[BUFFER_SIZE + 1];
    ssize_t     bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while ((bytes_read = read(fd, tmp_buffer, BUFFER_SIZE)) > 0)
    {
        tmp_buffer[bytes_read] = '\0';
        //printf("Read %zd bytes: %s\n", bytes_read, tmp_buffer); // Debugging print
        buffer = ft_strjoin(buffer, tmp_buffer);
        if (!buffer)
            return (NULL);
        //printf("Buffer after join: %s\n", buffer); // Debugging print
        if (ft_strchr(buffer, '\n'))
            break;
    }
    if (bytes_read < 0 || (bytes_read == 0 && (!buffer || *buffer == '\0')))
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
   // printf("Buffer before get_line: %s\n", buffer); // Debugging print
    char    *line = get_line(&buffer);
   // printf("Line returned: %s\n", line); // Debugging print
//    printf("Buffer after get_line: %s\n", buffer); // Debugging print
    return (line);
}
