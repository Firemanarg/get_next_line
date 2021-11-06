/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:47:59 by lsilva-q          #+#    #+#             */
/*   Updated: 2021/11/06 22:38:58 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strndup(const char *str, size_t n);
char	*ft_appstr(char *str1, char *str2, size_t len1, size_t len2);
size_t	ft_strlen(const char *str);
size_t	ft_cpynstr(char *dst, const char *src, size_t n);
char	*find_endl_chr(const char *str, size_t len);

#endif