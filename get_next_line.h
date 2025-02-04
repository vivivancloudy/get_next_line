/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:48:47 by thdinh            #+#    #+#             */
/*   Updated: 2025/02/04 17:52:11 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(const char *s, int c);
char    *ft_strncpy(char * dst, const char * src, size_t len);
size_t  ft_strlen(const char *s);
char *ft_strdup(const char *s);
char    *get_next_line(int fd);

#endif