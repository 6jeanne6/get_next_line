/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:01:07 by jewu              #+#    #+#             */
/*   Updated: 2024/01/01 20:44:57 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t n_memb, size_t size);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_substr(char const *s, unsigned int start, size_t len);

#endif

/*
 * sys/stat.h = manipulation of file metadata (modification date, rights)
 * fcntl.h = manipulate file descriptor
 * both libraries are used for open()
 * */