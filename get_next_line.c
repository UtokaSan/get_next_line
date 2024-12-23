/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:58:42 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/23 22:25:48 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static char	*read_data(int fd, char *buffer)
{
	char	*data;
	int		rbytes;
	char	*temp;

	data = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!data)
		return (NULL);
	rbytes = read(fd, data, BUFFER_SIZE);
	while (rbytes > 0)
	{
		data[rbytes] = '\0';
		if (!buffer)
			buffer = ft_strdup(data);
		else
		{
			temp = ft_strjoin(buffer, data);
			free(buffer);
			buffer = temp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(data);
	return (buffer);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_substr(buffer, 0, i + 1);
	else
		line = ft_strdup(buffer);
	return (line);
}

static char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_strdup(buffer + i + 1);
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_data(fd, buffer);
	if (!buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
