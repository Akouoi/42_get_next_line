/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:52:38 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/27 19:09:46 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*supercat(char *dest, char *src, size_t lu)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(dest);
	i = 0;
	while (i < lu || (src[i] && src[i] != '\n'))
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	if (i != lu && src[i] == '\n')
		dest[j++] = src[i];
	return (dest);
}

void	ft_strtrim(char *s1, char *c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	j = 0;
	if (s1[i] == *c)
		i++;
	while (j < len)
	{
		s1[j] = s1[i + j];
		j++;
	}
	s1[j] = '\0';
}

char	*free_return(char *line, int lu, char *tmp)
{
	if (!lu && *line)
	{
		bzero(tmp, BUFFER_SIZE);
		return (line);
	}
	if (!lu)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	tmp[BUFFER_SIZE + 1];
	char		*line;
	char		*buf;
	int			lu;

	if (BUFFER_SIZE < 1 || read(fd, tmp, 0) == -1)
		return (NULL);
	lu = BUFFER_SIZE;
	line = ft_calloc(1024, sizeof(char));
	buf = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (*tmp)
		ft_strlcpy(line, tmp, BUFFER_SIZE);
	if (!buf || !line || fd < 0)
		return (NULL);
	while (lu)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		lu = read(fd, buf, BUFFER_SIZE);
		line = supercat(line, buf, lu);
		if (ft_strchr(buf, '\n'))
		{
			ft_strlcpy(tmp, ft_strchr(buf, '\n'), BUFFER_SIZE);
			ft_strtrim(tmp, "\n");
			break ;
		}
	}
	free(buf);
	return (free_return(line, lu, tmp));
}
/*
int	main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	if (ac)
		fd = open(av[1], O_RDONLY);
	while (i < atoi(av[2]))
	{
		str = get_next_line(fd);
		printf("\n==========\ngnl  = %s\n==========\n", str);
		free(str);
		i++;
		printf("\n[%d]\n", i);
	}
	close(fd);
	return (0);
}*/
