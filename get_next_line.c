/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:03:59 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/10/26 20:34:06 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	************************************************************************* */
/*	*****************   S T A T I C   F U N C T I O N S   ******************* */
/*	************************************************************************* */

static char	*recursive_get_next_line(int fd, char **backup);
static char	*clearall_and_return_null(char **buffer, char **backup);
static char	*find_endl_char(char **buffer);

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
/*	************************************************************************* */

/*	************************************************************************* */

char	*get_next_line(int fd)
{
	static char	*backup;

	return (recursive_get_next_line(fd, &backup));
}

/*	************************************************************************* */

static char	*recursive_get_next_line(int fd, char **backup)
{
	char	*buffer;
	int		read_size;
	char	*endl_chr;
	char	*result;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size <= 0)
		return (clearall_and_return_null(&buffer, backup));
	buffer[read_size] = '\0';
	endl_chr = find_endl_char(&buffer);
	if (endl_chr)
	{
		*endl_chr = '\0';
		result = ft_append_str(*backup, buffer);
		if (backup)
			free(backup);
		backup = ft_strndup(endl_chr + 1, );	// Trocar por strdup

	}
}

/*	************************************************************************* */

static char	*clearall_and_return_null(char **buffer, char **backup)
{
	if (*buffer)
		free(*buffer);
	if (*backup)
		free(*backup);
	return (NULL);
}

/*	************************************************************************* */

static char	*find_endl_char(char **buffer)
{
	char	*chr;

	chr = *buffer;
	while (*chr != '\0')
	{
		if (*chr == '|')
			return (chr);
		chr++;
	}
	return (NULL);
}

/*	************************************************************************* */

/*	************************************************************************* */
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */
