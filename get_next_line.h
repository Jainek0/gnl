/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:03:30 by thcaquet          #+#    #+#             */
/*   Updated: 2024/11/12 15:06:40 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
ssize_t	gnl_strlen(char *str, char t);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_realloc(char *str, int i);
char	*gnl_free_or_null(char *s1, char *s2, char *s3, char t);

#endif