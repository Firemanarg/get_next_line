/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:43:02 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/11/10 17:08:57 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
/*	************************************************************************* */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;

	if (s == NULL)
		return (NULL);
	cc = c;
	while (*s != '\0')
	{
		if (*s == cc)
			return ((char *) s);
		s++;
	}
	if (cc == '\0')
		return ((char *) s);
	return (NULL);
}

/*	************************************************************************* */

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	len;
	size_t	index;
	char	*result;

	len = ft_strlen(str1) + ft_strlen(str2);
	if (len == 0)
		return (NULL);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (str1 && *str1)
	{
		result[index] = *str1;
		index += 1;
		str1++;
	}
	while (str2 && *str2)
	{
		result[index] = *str2;
		index += 1;
		str2++;
	}
	result[index] = '\0';
	return (result);
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

char	*ft_strdup(const char *str)
{
	char	*result;
	size_t	len;
	size_t	index;

	len = ft_strlen(str);
	if (len == 0)
		return (NULL);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		result[index] = str[index];
		index += 1;
	}
	result[len] = '\0';
	return (result);
}

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
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */