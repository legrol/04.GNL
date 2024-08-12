/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-24 07:02:58 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-04-24 07:02:58 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * The get_next_line() function write a function that returns the line read 
 * from a file descriptor.
 * 
 * @param int fd    file descriptor to read from.
 * 
 * returns  If all goes well: the line read
 *          On failure or if reading ends: NULL
 * 
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s);
	str = (char *) malloc((j + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	if (size < 1)
		return (count);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str3;
	size_t	totallen;
	int		i;
	int		j;

	totallen = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	str3 = (char *) malloc((totallen + 1) * sizeof(char));
	if (!str3)
		return (0);
	while (s1[i] != '\0')
	{
		str3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str3[i] = s2[j];
		i++;
		j++;
	}
	str3[i] = '\0';
	return (str3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *) s);
		else
			s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return (0);
}

static char	*manage_readed_line(char	*treat_line)
{
	char	*new_buffer_print;
	size_t	i;

	i = 0;
	while (treat_line[i] != '\n' && treat_line[i] != '\0')
		i++;
	if (treat_line[i] == 0 || treat_line[1] == 0)
		return (NULL);
	new_buffer_print = ft_substr(treat_line, i + 1, ft_strlen(treat_line) - i);
	if (*new_buffer_print == 0)
	{
		free(new_buffer_print);
		new_buffer_print = NULL;
	}
	treat_line[i + 1] = '\0';
	return (new_buffer_print);
}

static char	*read_fill_line(int fd, char *buffer_readed, char *buffer_print)
{
	ssize_t			bytes_readed;	
	char			*buffer_tmp;	

	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buffer_readed, BUFFER_SIZE);
		if (bytes_readed < 0)
		{
			free(buffer_readed);
			return (NULL);
		}
		else if (bytes_readed == 0)
			break ;
		buffer_readed[bytes_readed] = '\0';
		if (!buffer_print)
			buffer_print = ft_strdup("");
		buffer_tmp = buffer_print;
		buffer_print = ft_strjoin(buffer_tmp, buffer_readed);
		free(buffer_tmp);
		buffer_tmp = NULL;
		if (ft_strchr(buffer_readed, '\n'))
			break ;
	}
	return (buffer_print);
}

char	*get_next_line(int fd)
{
	char			*buffer_readed;
	char			*line_print;
	static char		*buffer_print[FD_SETSIZE];

	buffer_readed = (void *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
	{
		free(buffer_print[fd]);
		free(buffer_readed);
		buffer_print[fd] = NULL;
		buffer_readed = NULL;
		return (NULL);
	}
	if (!buffer_readed)
		return (NULL);
	line_print = read_fill_line(fd, buffer_readed, buffer_print[fd]);
	free(buffer_readed);
	buffer_readed = NULL;
	if (!line_print)
		return (NULL);
	buffer_print[fd] = manage_readed_line(line_print);
	return (line_print);
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*next_line;
	int		count;

	count = 1;
	fd1 = open("MyFile2sinacentos.txt", O_RDONLY);
	fd2 = open("MyFile1.txt", O_RDONLY);
	fd3 = open("MyFile2.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("File opening error");
		return (0);
	}
	while (count < 20)
	{
		next_line = get_next_line(fd1);
		if (next_line == NULL)
			break ;
		printf("[%d] fd1: %s\n", count, next_line);
		free(next_line);
		next_line = NULL;
		next_line = get_next_line(fd2);
		if (next_line == NULL)
			break ;
		printf("[%d] fd2: %s\n", count, next_line);
		free(next_line);
		next_line = NULL;
		next_line = get_next_line(fd3);
		if (next_line == NULL)
			break ;
		printf("[%d] fd3: %s\n", count, next_line);
		free(next_line);
		next_line = NULL;
		count++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
