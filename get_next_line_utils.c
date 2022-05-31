/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:25:50 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/31 14:27:28 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if ((size_t)-1 / size < nmemb)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		size = 1;
		nmemb = 1;
	}
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])// && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*p;

	p = (char *)s;
	if (c == '\0')
		return (p);
	while (*p)
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (NULL);
}


void	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return ;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}