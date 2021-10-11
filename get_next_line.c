/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:49:17 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/10/11 16:49:17 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t get_endl(const char *buffer)
{
	size_t	len;

	len = 0;
	while (*buffer != '\n' && *buffer != '\0')
	{
		len += 1;
		buffer++;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*result;
	size_t		endl_pos;
	int			result;

	buffer = (char *) malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	endl_pos = get_endl(buffer);
	return (ft_strndup(buffer, endl_pos));
}
