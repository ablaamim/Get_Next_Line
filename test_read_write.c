/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:11:20 by ablaamim          #+#    #+#             */
/*   Updated: 2021/11/25 08:23:44 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 4069

void	ft_putnbr(int n)
{
	long	nb;
	int		ret;
	char	buff[BUFFER_SIZE + 1];

	nb = (long) n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putstr_fd(int fd, char *s)
{
	while (*s)
		write(fd, s++, 1);
}

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

int	main(void)
{
	int		fd;
	int		ret;
	char	buff[BUFFER_SIZE + 1];

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		ft_putstr("open() failed.\n");
	ft_putstr("file descriptor value is : ");
	ft_putnbr(fd);
	write(1, "\n", 1);

	ret = read(fd, buff, BUFFER_SIZE);
	buff[ret] = '\0';
	ft_putnbr(ret);
	write(1, "\n", 1);
	ft_putstr(buff);
	write(1, "\n", 1);
	if (close(fd) == -1)
		ft_putstr("close() failed.\n");
	close(fd);
	// TRUNCATE SOME OF THE TEXT.
	fd = 0;
	fd = open("test.txt", O_WRONLY);
	if (fd == -1)
		ft_putstr("open() failed.\n");
	ft_putnbr(fd);
	write(1, "\n", 1);
	ft_putchar_fd(fd, 'W');
	ft_putstr_fd(fd, "RITE IN THE FD");
	if (close(fd) == -1)
		ft_putstr("close() failed\n");
	close(fd);
	return (EXIT_SUCCESS);
}
