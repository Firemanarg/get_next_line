/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:04:02 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/10/26 20:32:51 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
/*	************************************************************************* */

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

char	*ft_append_str(const char *str1, const char *str2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 + len2 > 0)
	{
		newstr = malloc((len1 + len2 + 1) * sizeof(char));
		if (newstr)
		{
			if (ft_cpynstr(new_str, str1, len1) == len1)
			{
				if (ft_cpynstr(new_str + len1, str2) == len2)
				{
					new_str[len1 + len2] = '\0';
					return (new_str);
				}
			}
			free(newstr);
		}
	}
	return (NULL);
}

/*	************************************************************************* */

size_t	ft_cpynstr(char *dst, const char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (*src != '\0' && index < n)
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

char	*ft_strndup(const char *str, size_t n)
{
	size_t	index;
	size_t	new_len;
	char	*new_str;

	new_len = 0;
	while (new_len < n && str[new_len] != '\0')
		new_len += 1;
	new_str = (char *) malloc((new_len * sizeof(char)) + 1);
	if (!new_str)
		return (NULL);
	index = 0;
	while (index < new_len)
	{
		new_str[index] = str[index];
		index += 1;
	}
	new_str[index] = '\0';
	return (new_str);
}

/*	************************************************************************* */

/*	************************************************************************* */
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */
