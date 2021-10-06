/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s </var/mail/rkenji-s>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:58:17 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/09/23 20:58:47 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n] != 0)
		n++;
	return (n);
}

int	my_count(char const *s, int start, int len)
{
	int	count;
	int	a;

	a = 0;
	count = 0;
	while (s[a] != '\0')
	{
		if (a >= start && count < len)
			count++;
		a++;
	}
	return (count);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		a;
	int		b;
	int		count;

	a = 0;
	b = 0;
	count = my_count(s, start, len);
	str = (char *) malloc (sizeof(char) * count + 1);
	if (str == NULL)
		return (NULL);
	while (s[a] != '\0')
	{
		if (a >= start && b < len)
		{
			str[b] = s[a];
			b++;
		}
		a++;
	}
	str[b] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		count;
	int		count2;

	count = 0;
	count2 = 0;
	s = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (s1[count] != '\0')
	{
		s[count] = s1[count];
		count++;
	}
	while (s2[count2] != '\0')
	{
		s[count] = s2[count2];
		count++;
		count2++;
	}
	free (s1);
	s[count] = '\0';
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	while (c > 255)
		c -= 256;
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *) s);
	return (NULL);
}
