/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-27 11:17:25 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-05-27 11:17:25 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>  //para typedef, malloc
# include <unistd.h> // para write()
# include <fcntl.h> // para open()
# include <stdio.h> // para printf()

//variable estatica para Buffer
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//funciones principales
char	*get_next_line(int fd);

//funciones utiles de ayuda
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif