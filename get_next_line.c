/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 04:47:01 by ablaamim          #+#    #+#             */
/*   Updated: 2021/12/10 05:23:22 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
*	FUNCTION : FT_IS_LINE

*	DESCRIPTION
*	This function checks if the string in the buffer contains a line.
*	A line is defined by the '\n' character.

*	RETURN VALUES
*	If the buffer contains a line, the function returns 1; otherwise, 
*	the function returns 0;
*/

int	ft_is_line(char	*buffer)
{
	while (*buffer)
	{
		if (*buffer++ == '\n')
			return (1);
	}
	return (0);
}

/*
*	FT_UPDATE_BUFFER
*
*	DESCRIPTION
*	This function updates the static_buffer with the buffer.
*/

void	ft_update_buffer(char	**static_buffer, char	**buffer)
{
	char	*temp;

	temp = *static_buffer;
	*static_buffer = ft_strjoin(temp, *buffer);
	free(temp);
}

/*
*	GET_LINE
*	
*	DESCRIPTION
*	This function takes the line that contains in static_buffer, and checks
*	if it has more content after the line, if it does, the function updates the
*	static_buffer with that content.
*	A line is defined by the '\n' character.
*	
*	RETURN VALUES
*	If static_buffer contains a line, the function returns a pointer with that
*	line; otherwise, the function returns a pointer to NULL;
*/

char	*get_line(char	**static_buffer, char	**line)
{
	size_t	line_len;
	char	*new_static_buffer;

	line_len = 0;
	new_static_buffer = NULL;
	while ((*static_buffer)[line_len] != '\n' \
			&& (*static_buffer)[line_len] != '\0')
		++line_len;
	if ((*static_buffer)[line_len] == '\n')
	{
		*line = ft_substr(*static_buffer, 0, (line_len + 1));
		new_static_buffer = ft_strdup(&(*static_buffer)[line_len + 1]);
	}
	else
		*line = ft_strdup(*static_buffer);
	free(*static_buffer);
	*static_buffer = new_static_buffer;
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	return (*line);
}

/*
*	READ_FILE
*	
*	DESCRIPTION
*	This function reads a file descriptor with read(2) and checks if the read
*	buffer has a line, if it doesn't have a line, the static_buffer is updated
*	with the contents of the buffer.
*	
*	RETURN VALUES
*	When the function finds a line or EOF, it returns the get_line function,
*	otherwise, if the read(2) function fails to read the file descriptor, the
*	function will return NULL;
*/

char	*read_file(int	fd, char	**buffer)
{
	static char	*static_buffer = NULL;
	char		*line;
	ssize_t		n;

	n = 1;
	if (!static_buffer)
		static_buffer = ft_strdup("");
	while (!is_line(static_buffer) && n)
	{
		n = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[n] = '\0';
		att_buffer(&static_buffer, buffer);
	}
	free(*buffer);
	*buffer = NULL;
	return (get_line(&static_buffer, &line));
}

/*
*	GET_NEXT_LINE
*
*	DESCRIPTION
*	Write a function which returns a line read from a
*	file descriptor.
*	
*	RETURN VALUES
*	Read line: correct behavior.
*	NULL: nothing else to read or an error occurred.
*/

char	*get_next_line(int	fd)
{
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	return (read_file(fd, &buffer));
}
