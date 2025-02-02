/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:18:53 by jgraf             #+#    #+#             */
/*   Updated: 2024/12/12 16:02:23 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


/*	These functions are used to read the file and manage the buffer.
*	They are used to check if the file is empty or if there is an error.
*	They are also used to manage the buffer index, which is responsable for
*	checking if the buffer has content left.
*/

static int	read_error(int bytes, char *linebuf)
{
	if (bytes <= 0)
	{
		if (bytes < 0 || linebuf[0] == '\0')
			return (-1);
		return (0);
	}
	return (1);
}

static int	buffidx_manage(char *buffer, int index, int	*complete)
{
	while (buffer[index] != '\0' && buffer[index] != '\n')
		index ++;
	if (buffer[index] == '\n')
	{
		*complete = 1;
		index ++;
	}
	return (index);
}

static int	linebuf_setup(char **linebuf, int *complete)
{
	*linebuf = malloc(1);
	if (*linebuf == NULL)
		return (0);
	(*linebuf)[0] = '\0';
	*complete = 0;
	return (1);
}

static int	read_from_fd(int fd, char *buffer, int *index)
{
	int	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes > 0)
		buffer[bytes] = '\0';
	*index = 0;
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	read_bytes = 0;
	static int	buffer_index = 0;
	char		*linebuf;
	int			complete;

	if (!linebuf_setup(&linebuf, &complete) || BUFFER_SIZE <= 0 || fd < 0)
		return (free_mem(linebuf), NULL);
	while (!complete)
	{
		if (buffer_index >= read_bytes)
		{
			read_bytes = read_from_fd(fd, buffer, &buffer_index);
			if (read_error(read_bytes, linebuf) == -1)
				return (free_mem(linebuf), NULL);
			if (read_error(read_bytes, linebuf) == 0)
				break ;
		}
		linebuf = append(linebuf, buffer + buffer_index, read_bytes);
		buffer_index = buffidx_manage(buffer, buffer_index, &complete);
		if (linebuf == NULL)
			return (NULL);
	}
	return (linebuf);
}