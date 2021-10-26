/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:03:30 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/10/26 20:33:01 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_append_str(const char *str1, const char *str2);
char	*ft_strndup(const char *str, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_cpynstr(char *dst, const char *src, size_t n);

#endif
