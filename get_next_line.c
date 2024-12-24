/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:58:42 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/24 12:03:02 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static int	find_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*read_data(int fd, char *buffer)
{
	char	*data;
	int		rbytes;

	data = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!data)
		return (NULL);
	rbytes = read(fd, data, BUFFER_SIZE);
	while (rbytes > 0)
	{
		data[rbytes] = '\0';
		buffer = insert_buffer(buffer, data);
		if (find_newline(buffer) >= 0)
			break ;
		rbytes = read(fd, data, BUFFER_SIZE);
	}
	free(data);
	if (rbytes < 0)
	{
		return (free(buffer), NULL);
	}
	return (buffer);
}

static char	*extract_line(char *buffer)
{
	int		newline_index;
	char	*line;

	newline_index = find_newline(buffer);
	if (newline_index >= 0)
		line = ft_substr(buffer, 0, newline_index + 1);
	else
		line = ft_strdup(buffer);
	return (line);
}

static char	*update_buffer(char *buffer)
{
	int		newline_index;
	char	*new_buffer;

	newline_index = find_newline(buffer);
	if (newline_index < 0)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_strdup(buffer + newline_index + 1);
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

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
} */
