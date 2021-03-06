/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:43:00 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/11/12 01:45:21 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	************************************************************************* */
/*	*****************   S T A T I C   F U N C T I O N S   ******************* */
/*	************************************************************************* */

static char	*initial_validation(char **backup);
static char	*read_line(int fd, char **backup, char **buffer);
static char	*clear_all_and_return_null(char **backup, char **buffer);

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
/*	************************************************************************* */

char	*get_next_line(int fd)
{
	static char	*backup = NULL;
	char		*buffer;
	char		*tmp;

	buffer = NULL;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (clear_all_and_return_null(&backup, &buffer));
	buffer = initial_validation(&backup);
	if (buffer)
		return (buffer);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (clear_all_and_return_null(&backup, &buffer));
	tmp = read_line(fd, &backup, &buffer);
	return (tmp);
}

/*	************************************************************************* */

static char	*initial_validation(char **backup)
{
	char	*endl_chr;
	char	*temp1;
	char	*temp2;

	endl_chr = ft_strchr(*backup, '\n');
	if (!endl_chr)
		endl_chr = ft_strchr(*backup, 1);
	if (endl_chr)
	{
		if (*endl_chr == 1)
			*endl_chr = '\0';
		temp1 = ft_strndup(*backup, (endl_chr - *backup) + 1);
		temp2 = ft_strdup(endl_chr + 1);
		free(*backup);
		*backup = temp2;
		return (temp1);
	}
	return (NULL);
}

/*	************************************************************************* */

static char	*read_line(int fd, char **backup, char **buffer)
{
	char	*temp;
	int		read_bytes;

	read_bytes = read(fd, *buffer, BUFFER_SIZE);
	if (read_bytes > 0)
	{
		(*buffer)[read_bytes] = '\0';
		temp = ft_strjoin(*backup, *buffer);
		free(*backup);
		free(*buffer);
		*backup = temp;
		return (get_next_line(fd));
	}
	else if (read_bytes < 0)
		return (clear_all_and_return_null(backup, buffer));
	free(*buffer);
	buffer = NULL;
	temp = ft_strdup(*backup);
	free(*backup);
	*backup = NULL;
	return (temp);
}

/*	************************************************************************* */

static char	*clear_all_and_return_null(char **backup, char **buffer)
{
	if (*backup)
	{
		free(*backup);
		*backup = NULL;
	}
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

/*	************************************************************************* */
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */
