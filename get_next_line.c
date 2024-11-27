/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:58:42 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/27 17:43:56 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	bytes_read = 1;
	line = NULL;
	read_and_store(fd, &buffer, &bytes_read);
	if (buffer == NULL)
		return (NULL);
	return (line);
}

void	read_and_store(int fd, char **buffer, int *bytes_read)
{
	char	*temp;
	char	*buff;
	int		i;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return ;
	while (*bytes_read > 0 && !ft_strchr(*buffer, '\n'))
	{
		*bytes_read = read(fd, buff, BUFFER_SIZE);
		if (*bytes_read < 0)
			break ;
		buff[*bytes_read] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(*buffer, buff);
		free(temp);
	}
	free(buff);
}
