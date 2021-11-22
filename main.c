/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:57:56 by ablaamim          #+#    #+#             */
/*   Updated: 2021/11/22 15:38:09 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	int		fd;
	char	*s = (char *) malloc (sizeof (char) * 2000000);

	fd = open("file.txt", O_WRONLY | O_CREAT);
	write(fd, s, 2000000 * sizeof(char));
	close(fd);
	free(s);
	return (EXIT_SUCCESS);
}
