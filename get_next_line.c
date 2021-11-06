/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:47:34 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/11/06 22:38:56 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	************************************************************************* */
/*	*****************   S T A T I C   F U N C T I O N S   ******************* */
/*	************************************************************************* */

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
/*	************************************************************************* */

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*result;
	char		*endl_chr;
	size_t		read_bytes;

	if (backup)
	{
		endl_chr = find_endl_chr(backup, ft_strlen(backup));
		if (endl_chr)
		{
			result = ft_strndup(backup, (endl_chr - backup) + 1);
			if ((endl_chr - backup) + 1 < (long) ft_strlen(backup))
			{
				buffer = ft_strndup(endl_chr + 1, ft_strlen(endl_chr + 1));
				free(backup);
				backup = NULL;
				backup = buffer;
			}
			else
			{
				free(backup);
				backup = NULL;
			}
			return (result);
		}
	}
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
	{
		if (buffer)
			free(buffer);
		if (backup)
		{
			result = ft_strndup(backup, ft_strlen(backup));
			free(backup);
			backup = NULL;
		}
		else
			return (NULL);
	}
	else
	{
		endl_chr = find_endl_chr(buffer, ft_strlen(buffer));
		if (endl_chr)
		{
			result = ft_appstr(backup, buffer, ft_strlen(backup), (endl_chr - buffer) + 1);
			if (backup)
				free(backup);
			if ((endl_chr - buffer) + 1 < (long) ft_strlen(buffer))
				backup = ft_strndup(endl_chr + 1, ft_strlen(endl_chr + 1));
			free(buffer);
		}
		else
		{
			result = ft_appstr(backup, buffer, ft_strlen(backup), ft_strlen(buffer));
			if (backup)
			{
				free(backup);
				backup = NULL;
			}
			if (buffer)
				free(buffer);
			backup = result;
			result = get_next_line(fd);
		}
	}
	return (result);
}

/*	************************************************************************* */
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */
