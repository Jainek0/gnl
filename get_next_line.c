/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:03:16 by thcaquet          #+#    #+#             */
/*   Updated: 2024/11/14 15:25:05 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_sep(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}


char	*get_scrap(char **scrap)
{
	size_t	i;
	size_t	j;
	char	*old_buffer;

	i = get_sep(*scrap);
	j = 0;
	if (i == 0)
		i = gnl_strlen(*scrap, 'F');
	old_buffer = malloc(i + 1);
	if (!old_buffer)
		return (0);
	while (j++ < i)
		old_buffer[j - 1] = scrap[0][j - 1];
	old_buffer[i] = 0;
	*scrap = gnl_realloc(*scrap, i);
	return (old_buffer);
}

char	*get_buffer(char *old_buffer, char **scrap, int fd)
{
	char	*buffer;
	char	*nextl;
	ssize_t	i;
	ssize_t	j;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	buffer[0] = 0;
	i = 0;
	while (i == 0)
	{
		old_buffer = gnl_strjoin(old_buffer, buffer);
		j = read(fd, buffer, BUFFER_SIZE);
		if (j <= 0)
		{
			gnl_free_or_null(buffer, old_buffer, *scrap, 'F');
			return (0);
		}
		buffer[j] = 0;
		i = get_sep(buffer);
	}
	j = 0;
	nextl = gnl_strjoin(old_buffer, buffer);
	if (!nextl)
		return (0);
	gnl_free_or_null(NULL, NULL, *scrap, 'F');
	*scrap = gnl_realloc(buffer, i);
	return (nextl);
}

char	*get_next_line(int fd)
{
	static char	*scrap;
	char		*old_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!scrap)
	{
		scrap = gnl_free_or_null(NULL, NULL, NULL, 'N');
		if (!scrap)
			return (0);
	}
	old_buffer = get_scrap(&scrap);
	if (get_sep(old_buffer))
		return (old_buffer);
	old_buffer = get_buffer(old_buffer, &scrap, fd);
	return (old_buffer);
}
