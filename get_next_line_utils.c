/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:11:45 by thdinh            #+#    #+#             */
/*   Updated: 2025/02/04 17:48:57 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strdup(const char *s)
{
    char *dup;
    int i;
    int size;

    size = ft_strlen(s);
    dup = (char *)malloc(sizeof(char) * (size + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (*s)
        dup[i++] = *s++;
    dup[i] = '\0';
    return (dup);
}

char *ft_strjoin(char *s1, char *s2)
{
    char  *joined;
    int   i;
    int   j;

    if (!s1 || !s2)
        return (NULL);
    if (!s1)
        return (ft_strdup(""));
    joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!joined)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        joined[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
        joined[i++] = s2[j++];
    joined[i] = '\0';
    free(s1);
    return(joined);
}

char    *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return(NULL);
}

char    *ft_strncpy(char * dst, const char * src, size_t len)
{
    size_t i;

    i = 0;
    while (src[i] && i < len)
    {
        dst[i] = src[i];
        i++;
    }
    while (i < len)
        dst[i++] = '\0';
    return (dst);
}