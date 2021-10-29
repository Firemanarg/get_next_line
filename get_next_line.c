/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:59:38 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/10/29 23:55:41 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	************************************************************************* */
/*	*****************   S T A T I C   F U N C T I O N S   ******************* */
/*	************************************************************************* */

static char	*clearall_and_return_null(char **buffer, char **backup);
static char	*find_endl_chr(const char *str, size_t len);
static char	*endl_at_backup(char **buffer, char **backup, char *endl_chr);
static char	*endl_at_buffer(char **buffer, char **backup, char *endl_chr);

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
/*	************************************************************************* */

char    *get_next_line(int fd)
{
    static char    *backup;
    char        *buffer;
    char        *endl_chr;
    char        *result;
    int            read_bytes;
    size_t        len;

    if (fd <= 0)
        return (clearall_and_return_null(&buffer, &backup));
    endl_chr = find_endl_chr(backup, ft_strlen(backup));
    if (endl_chr)
    {
        result = ft_strndup(backup, (endl_char - backup) + 1);
        if (result == NULL)
            return (clearall_and_return_null(&buffer, &backup));
        len = ft_strlen(backup) - ((endl_chr - backup) + 1);
        buffer = ft_strndup(backup, len);
        if (buffer == NULL && len > 0)
            return (clearall_and_return_null(&buffer, &backup));
        free(backup);
        backup = buffer;
        return (result);
    }
    buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL)
        return (clearall_and_return_null(&buffer, &backup));
    read_bytes = read(fd, buffer, BUFFER_SIZE);
    if (read_bytes <= 0)
        return (clearall_and_return_null(&buffer, &backup));
    endl_chr = find_endl_chr(buffer, read_bytes);
    if (endl_char)
    {
        len = (endl_chr - buffer) + 1;
        result = ft_appendstr(backup, buffer, ft_strlen(backup), len);
        if (backup)
            free(backup);
        backup = ft_strndup(endl_chr + 1, read_bytes - len);
        if (buffer)
            free(buffer);
        return (result);
    }
    result = ft_appendstr(backup, buffer, ft_strlen(backup), read_bytes);
    clearall_and_return_null(&buffer, &backup);
    backup = result;
    return (get_next_line(fd));
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

static char	*find_endl_chr(const char *str, size_t len)
{
	size_t	i;

	if (str != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (*str == '\n' || *str == '\0')
				return (str);
			str++;
		}
	}
	return (NULL);
}

/*	************************************************************************* */
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */
