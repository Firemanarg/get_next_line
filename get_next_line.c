/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:49:42 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/10/11 18:12:42 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	freeall(char **backup, char **buffer)
{
	if (*backup)
	{
		free(*backup);
		*backup = NULL;
	}
	if (*buffer)
	{
		free(*buffer);
		*backup = NULL;
	}
}

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

// static char	*generate_result(char **backup, char **buffer)
// {
// 	size_t	endl_pos;
// 	size_t	backup_len;
// 	size_t	buffer_len;

// 	endl_pos = get_endl(buffer);
// 	buffer_len = ft_strlen(*buffer);
// 	if (buffer_len > 0)
// 	{
// 		if (*backup == NULL)
// 		{
// 			backup_len = 0;
// 			*backup = ft_memcpy((*buffer + endl_pos), ) // Copiar da posição buffer[endl_pos] para backup, com len = buffer_len - endl_pos
// 			ft_cpynstr(*backup, (*buffer + endl_pos), (buffer_len - endl_pos));
// 		}
// 		if (*backup)
// 			backup_len = ft_strlen(*backup);
// 	}
// }

// BUFFER_SIZE -> 8
// 		0  1  2  3  4  5  6  7
// 		A  B  C  D  E  F  G  H
// 		A  B  C  D  E  \n F  G
// 		A  B  C  \n D  E  F  G
// 		\n A  B  C  D  E  F  G
// 		A  B  C


static void	updt_backup(char **bkp, char **bff, size_t cpy_size, size_t bff_len)
{
	if (*bkp)
		free(*bkp);
	if (cpy_size < bff_len)
	{
		// *bkp = (char *) malloc((bff_len - cpy_size) * sizeof(char) + 1);
		*bkp = (char *) malloc((bff_len - cpy_size) * sizeof(char));
		if (*bkp)
		{
			// *bkp = ft_strndup(*bff, bff_len - cpy_size);
			*bkp = ft_strndup(*bff, bff_len - cpy_size - 1);
			return ;
		}
	}
	*bkp = NULL;
}

static char	*generate_result(char **backup, char **buffer)
{
	size_t	endl_pos;
	size_t	buffer_len;
	size_t	backup_len;
	size_t	cpy_size;
	char	*result;

	endl_pos = get_endl(*buffer);
	buffer_len = ft_strlen(*buffer);
	backup_len = 0;
	if (*backup)
		backup_len = ft_strlen(*backup);
	if (backup_len + endl_pos >= BUFFER_SIZE)
	{
		// result = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
		result = (char *) malloc(BUFFER_SIZE * sizeof(char));
		cpy_size = BUFFER_SIZE - backup_len - 1;
	}
	else
	{
		// result = (char *) malloc(backup_len + endl_pos * sizeof(char) + 1);
		result = (char *) malloc(backup_len + endl_pos * sizeof(char));
		cpy_size = buffer_len - 1;
	}
	ft_cpynstr(result, *backup, backup_len);
	if (*backup)
		ft_cpynstr(result + backup_len, *buffer, cpy_size);
	updt_backup(backup, buffer, cpy_size, buffer_len);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*result;
	int			read_out;

	buffer = (char *) malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!backup)
		backup = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buffer || !backup)
	{
		freeall(&backup, &buffer);
		return (NULL);
	}
	read_out = read(fd, buffer, BUFFER_SIZE);
	if (read_out <= 0)
	{
		freeall(&backup, &buffer);
		return (NULL);
	}
	result = generate_result(&backup, &buffer);
	if (!result)
		freeall(&backup, &buffer);
	return (result);
}
