/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 04:49:21 by ablaamim          #+#    #+#             */
/*   Updated: 2021/12/10 04:49:25 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*
*	FT_STRLEN
*
*	DESCRIPTION
*	The strlen() function computes the length of the string str.
*
*	RETURN VALUES
*	The strlen() function returns the number of characters that precede the
*	terminating NUL character.
*/

size_t	ft_strlen(const char	*str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

/*
*	FT_STRDUP
*
*	DESCRIPTION
*	The strdup() function allocates sufficient memory for a copy of the
*	string str, does the copy, and returns a pointer to it. The pointer may
*	subsequently be used as an argument to the function free(3).
*
*	RETURN VALUES
*	If insufficient memory is available, NULL is returned and errno is set
*	to ENOMEM.
*/

char	*ft_strdup(const char	*str)
{
	size_t	len;
	char	*dup;

	len = (ft_strlen(str) + 1);
	dup = (char *)malloc(len * sizeof(*str));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, len);
	return (dup);
}

/*
*	FT_STRLCPY
*
*	DESCRIPTION
*	The strlcpy() function copy strings with the same input parameters and
*	output result as snprintf(3).  It is designed to be safer, more
*	consistent, and less error prone replacements for the easily misused
*	function strncpy(3).
*
*	The strlcpy() take the full size of the destination buffer and
*	guarantee NUL-termination if there is room.  Note that room for the NUL
*	should be included in dstsize.
*
*	The strlcpy() copies up to dest_size - 1 characters from the string src
*	to dest, NUL-terminating the result if dest_size is not 0.
*
*	If the src and dest strings overlap, the behavior is undefined.
*
*	RETURN VALUES
*	Besides quibbles over the return type (size_t versus int) and signal
*	handler safety (snprintf(3) is not entirely safe on some systems), the
*	following two are equivalent:
*
*		n = strlcpy(dest, src, len);
*		n = snprintf(dst, len, "%s", src);
*
*	Like snprintf(3), the strlcpy() function return the total length of the
*	string they tried to create, that means the length of src.
*
*	If the return value is >= dest_size, the output string has been
*	truncated.  It is the caller's responsibility to handle this.
*/

size_t	ft_strlcpy(char	*dest, const char	*src, size_t	dest_size)
{
	size_t	src_len;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (dest_size)
	{
		while (--dest_size && *src)
			*(dest++) = *(src++);
		*dest = '\0';
	}
	return (src_len);
}

/*
*	FT_STRJOIN
*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a new string, which
*	is the result of the concatenation of ’str1’ and ’str2’.
*
*	RETURN VALUES
*	The new string. NULL if the allocation fails.
*/

char	*ft_strjoin(const char	*str1, const char	*str2)
{
	size_t	str1_len;
	size_t	str2_len;
	char	*new_str;

	if (!str1 && !str2)
		return (NULL);
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	new_str = (char *)malloc((str1_len + str2_len + 1) * sizeof(*new_str));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str1, (str1_len + 1));
	ft_strlcpy((new_str + str1_len), str2, (str2_len + 1));
	return (new_str);
}

/*
*	FT_SUBSTR
*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a substring from the string ’str’.
*	The substring begins at index ’start’ and is of maximum size ’len’.
*
*	RETURN VALUES
*	The substring. NULL if the allocation fails.
*/

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_start_len;

	if (!str)
		return (NULL);
	if (ft_strlen(str) < start)
		return (ft_strdup(""));
	s_start_len = ft_strlen((str + start));
	if (s_start_len < len)
		len = s_start_len;
	++len;
	sub = (char *)malloc(len * sizeof(*sub));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (str + start), len);
	return (sub);
}
