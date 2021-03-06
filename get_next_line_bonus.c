/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s </var/mail/rkenji-s>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:57:51 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/09/23 20:57:53 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_loop(int fd, char *buff, char *str)
{
	int	size;

	size = 1;
	while (!ft_strchr(buff, '\n') && size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free (buff);
			free (str);
			return (NULL);
		}
		buff[size] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

char	*get_big_line(int fd, char *str)
{
	char	*buff;

	if (!str)
	{
		str = malloc (sizeof(char) * 1);
		str[0] = '\0';
	}
	buff = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	str = read_loop (fd, buff, str);
	if (str == NULL)
		return (NULL);
	free (buff);
	if (str[0] == '\0')
	{
		free (str);
		return (NULL);
	}
	return (str);
}

char	*get_line(char	*big_line)
{
	char	*line;
	int		count;

	count = 0;
	while (big_line[count] != '\0' && big_line[count] != '\n')
		count++;
	line = ft_substr(big_line, 0, count + 1);
	return (line);
}

char	*get_str(char *big_line)
{
	int		count;
	char	*new_str;

	count = 0;
	while (big_line[count] != '\0' && big_line[count] != '\n')
		count++;
	if (big_line[count] == '\n')
	{
		count++;
		new_str = ft_substr(big_line, count, ft_strlen(big_line) - count);
		free (big_line);
		return (new_str);
	}
	free (big_line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*line;
	char		*big_line;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	else
	{
		big_line = get_big_line(fd, str[fd]);
		if (big_line == NULL)
			return (NULL);
		line = get_line(big_line);
		str[fd] = get_str(big_line);
		return (line);
	}
}
