/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:59:25 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/24 12:01:55 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*insert_buffer(char	*buffer, char *data)
{
	char	*temp;

	if (!buffer)
		temp = ft_strdup(data);
	else
	{
		temp = ft_strjoin(buffer, data);
		free(buffer);
	}
	return (temp);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && str[start + i] != '\0')
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	if (!str)
		return (NULL);
	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	join = calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		join[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}
