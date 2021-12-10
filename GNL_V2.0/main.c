/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:09:31 by ablaamim          #+#    #+#             */
/*   Updated: 2021/12/10 10:56:32 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	char	*line;
	int i = 0;
	int	fd = open("test.txt", O_RDONLY);
	while (i < 6)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close (fd);
	return (EXIT_SUCCESS);
}