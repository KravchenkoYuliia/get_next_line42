/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:27:45 by yukravch          #+#    #+#             */
/*   Updated: 2025/02/23 14:56:16 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *reserve, char *buffer)
{
	char	*array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	array = ft_calloc(ft_strlen(reserve) + ft_strlen(buffer) + 1, 1);
	if (!array)
		return (free(reserve), NULL);
	while (reserve[i])
	{
		array[i] = reserve[i];
		i++;
	}
	while (buffer != NULL && buffer[j])
	{
		array[i + j] = buffer[j];
		j++;
	}
	free(reserve);
	return (array);
}

char	*ft_get_line(char *reserve)
{
	size_t	i;
	char	*line;

	i = 0;
	line = (char *)ft_calloc(ft_strlen_line(reserve) + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (reserve != NULL && reserve[i] && reserve[i] != '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	ft_strcpy(reserve, &reserve[i]);
	line[i] = '\0';
	return (line);
}

char	*ft_strdup(char *buffer)
{
	char	*array;
	int		l;
	int		i;

	i = 0;
	l = ft_strlen(buffer);
	array = (char *)ft_calloc(l + 1, sizeof(char));
	if (!array)
		return (NULL);
	while (buffer[i])
	{
		array[i] = buffer[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		buffer[BUFFER_SIZE + 1];
	static char		*reserve;
	int				read_return;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ft_bzero(buffer, BUFFER_SIZE);
	read_return = 1;
	while (read_return != 0 && !ft_strchr(reserve, '\n'))
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return < 0)
			return (free(reserve), reserve = NULL);
		buffer[read_return] = '\0';
		if (!reserve)
			reserve = ft_strdup(buffer);
		else
			reserve = ft_strjoin(reserve, buffer);
	}
	if (reserve [0] == '\0')
		return (free(reserve), (reserve = NULL));
	line = ft_get_line(reserve);
	return (line);
}	

/*	
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{

	int fd = open("1char", O_RDONLY);
	if (fd == -1)
		return (0);

	char *line;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
}
*/
