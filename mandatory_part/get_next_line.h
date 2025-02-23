/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:25:24 by yukravch          #+#    #+#             */
/*   Updated: 2024/12/19 12:08:34 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char *reserve, char *buffer);
char	*ft_get_line(char *reserve);
char	*ft_strdup(char *buffer);
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(char *str);
size_t	ft_strlen_line(char *line);
int		ft_strchr(const char *s, int c);

#endif
