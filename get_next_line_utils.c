/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:11:45 by thdinh            #+#    #+#             */
/*   Updated: 2025/02/05 12:51:32 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    while (s && s[i])
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
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	char *result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return(NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2);
	result[len1 + len2] = '\0';
	free(s1);
	return(result);
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

void    *ft_memcpy(void * dst, const void * src, size_t n)
{
	size_t	i;
	const char	*s;
 	char	*d; 	

	s = (const char*)src;
	d = (char *) dst;
	if (!dst || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return(dst);
}
