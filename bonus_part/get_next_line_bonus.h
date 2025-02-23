/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:59:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/01/12 19:40:28 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_cut_line(char *reserve);
char	*ft_copy_from_buffer(char *reserve, char *buffer);
char	*ft_get_line(char *full_reserve);
char	*ft_read_buffer(int fd, char *reserve);
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strchr(const char *s, int c);

#endif
