/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 04:48:32 by ablaamim          #+#    #+#             */
/*   Updated: 2021/12/10 05:23:47 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

//	get_next_line functions
int		ft_is_line(char	*buffer);
void	ft_update_buffer(char	**static_buffer, char	**buffer);
char	*get_line(char	**static_buffer, char	**line);
char	*read_file(int	fd, char	**buffer);
char	*get_next_line(int	fd);

//	utils functions
size_t	ft_strlen(const char	*str);
char	*ft_strdup(const char	*str);
size_t	ft_strlcpy(char	*dest, const char	*src, size_t	dest_size);
char	*ft_strjoin(const char	*str1, const char	*str2);
char	*ft_substr(char const *str, unsigned int start, size_t len);

#endif
