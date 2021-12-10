/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:43:19 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/14 15:48:56 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//	get_next_line functions
int		is_line(char	*buffer);
void	att_buffer(char	**static_buffer, char	**buffer);
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
