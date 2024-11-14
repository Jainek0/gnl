/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:03:42 by thcaquet          #+#    #+#             */
/*   Updated: 2024/11/14 15:25:09 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	gnl_strlen(char *str, char t)
{
	ssize_t	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n' && t == 'T')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*gnl_realloc(char *str, int i)
{
	char	*new_str;
	ssize_t	j;
	ssize_t	len;

	j = 0;
	len = gnl_strlen(&str[i], 'F');
	new_str = malloc(len + 1);
	if (!new_str)
		return (0);
	while (str[i + j++])
		new_str[j - 1] = str[i + j - 1];
	new_str[j - 1] = 0;
	gnl_free_or_null(str, NULL, NULL, 'F');
	return (new_str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		l1;
	int		l2;
	int		i;
	char	*str;

	l1 = 0;
	l2 = 0;
	if (s1)
		l1 = gnl_strlen(s1, 'T');
	if (s2)
		l2 = gnl_strlen(s2, 'T');
	i = -1;
	str = (char *) malloc(l1 + l2 + 1);
	if (!str)
		return (0);
	while (++i < l1)
		str[i] = s1[i];
	i--;
	while ((++i - l1) < l2)
		str[i] = s2[i - l1];
	str[i] = 0;
	gnl_free_or_null(s1, NULL, NULL, 'F');
	return (str);
}

char	*gnl_free_or_null(char *s1, char *s2, char *s3, char t)
{
	char	*str;

	if (t == 'N')
	{
		str = malloc(1);
		if (str)
			str[0] = 0;
		return (str);
	}
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	if (s3)
	{
		free(s3);
		s3 = NULL;
	}
	return (0);
}

