/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:00:15 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/10/29 23:53:11 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
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

char	*ft_appendstr(const char *str1, const char *str2, size_t l1, size_t l2)
{
	char	*new_str;

	if (l1 + l2 > 0)
	{
		new_str = malloc((l1 + l2 + 1) * sizeof(char));
		if (new_str)
		{
			if (ft_cpynstr(new_str, str1, l1) == l1)
			{
				if (ft_cpynstr(new_str + l1, str2) == l2)
				{
					new_str[l1 + l2] = '\0';
					return (new_str);
				}
			}
			free(new_str);
		}
	}
	return (NULL);
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
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */
