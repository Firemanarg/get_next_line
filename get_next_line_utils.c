/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:48:02 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/11/06 22:38:50 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
/*	************************************************************************* */

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*new_str;

	if (str == NULL || n == 0)
		return (NULL);
	new_str = malloc(n * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new_str[i] = str[i];
		i += 1;
	}
	return (new_str);
}

/*	************************************************************************* */

size_t	ft_strlen(const char *str)
{
	const char	*s;

	if (str == NULL)
		return (0);
	s = str;
	while (*s)
		s++;
	return (s - str);
}

/*	************************************************************************* */

char	*ft_appstr(char *str1, char *str2, size_t len1, size_t len2)
{
	size_t	total_len;
	char	*new_str;

	total_len = 0;
	if (str1 && len1 > 0)
		total_len += len1;
	if (str2 && len2 > 0)
		total_len += len2;
	if (total_len == 0)
		return (NULL);
	new_str = malloc((total_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_cpynstr(new_str, str1, len1);
	ft_cpynstr(new_str + len1, str2, len2);
	new_str[len1 + len2] = '\0';
	return (new_str);
}

/*	************************************************************************* */

size_t	ft_cpynstr(char *dst, const char *src, size_t n)
{
	size_t	index;

	if (dst == NULL || src == NULL || n == 0)
		return (0);
	index = 0;
	while (index < n)
	{
		*dst = *src;
		dst++;
		src++;
		index += 1;
	}
	*dst = '\0';
	return (index);
}

/*	************************************************************************* */

char	*find_endl_chr(const char *str, size_t len)
{
	size_t	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (str[i] == '\n')
			return ((char *) str + i);
		else if (str[i] == '\0')
		{
			if ((char *) str != (char *) str + i)
				return ((char *) str + i - 1);
			break ;
		}
		i += 1;
	}
	return (NULL);
}

/*	************************************************************************* */
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */
