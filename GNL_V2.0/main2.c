/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:28:27 by ablaamim          #+#    #+#             */
/*   Updated: 2021/12/10 13:35:34 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	int	fd1 = open("test0.txt", O_RDONLY);
	char	*line = get_next_line_bonus(fd);
	char	*line1 = get_next_line_bonus(fd1);

	while (line1 != NULL && line != NULL)
	{
		printf("%s", line);
		printf("%s", line1);
		free(line);
		free(line1);
		line = get_next_line_bonus(fd);
		line1 = get_next_line_bonus(fd1);
	}
	close(fd);
	close(fd1);
	return (EXIT_SUCCESS);
}
