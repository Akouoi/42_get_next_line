/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:27:12 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/31 14:28:05 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <string.h>

char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
void	ft_strtrim(char *s1, char *c);
char	*ft_strchr(char *s, int c);
void	ft_strlcpy(char *dest, char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
