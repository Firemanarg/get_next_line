/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:26:46 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/10/07 11:26:46 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

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