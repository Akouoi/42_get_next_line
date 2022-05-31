/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:52:38 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/31 14:26:04 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*supercat(char *dest, char *src, size_t lu)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(dest);
	i = 0;
	while (i < lu && (src[i] && src[i] != '\n'))
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
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
	static char	tmp[1024][BUFFER_SIZE + 1];
	char		*line;
	int i =0;
	int			lu;

	if (fd< 0 || BUFFER_SIZE < 1 || read(fd, tmp[fd], 0) == -1)
		return (NULL);
	lu = BUFFER_SIZE;
	line = ft_calloc(1024, sizeof(char));
	if (!line)
		return (NULL);
	if (tmp[fd])
		ft_strlcpy(line, tmp[fd], BUFFER_SIZE);
	while (lu)
	{
		lu = read(fd, tmp[fd], BUFFER_SIZE);
		tmp[fd][lu] = '\0';
		printf("\n==================buf [%d] ; %s, lu = %i\n", ++i, tmp[fd], lu);

		line = supercat(line, tmp[fd], lu);
		printf("\n line [%d] == %s\n", fd, line);
		
		if (ft_strchr(tmp[fd], '\n'))
		{
			ft_strlcpy(tmp[fd], ft_strchr(tmp[fd], '\n'), BUFFER_SIZE);
			printf("\n tmp [%d] == %s\n", fd, tmp[fd]);
			
			ft_strtrim(tmp[fd], "\n");
			printf("\n tmp [%d] == %s\n", fd, tmp[fd]);

			break ;
		}
	}
	return (free_return(line, lu, tmp[fd]));
}

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
}
