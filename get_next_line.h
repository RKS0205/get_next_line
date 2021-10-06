/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s </var/mail/rkenji-s>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:59:45 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/09/23 20:59:51 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
int		my_count(char const *s, int start, int len);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*get_str(char *big_line);
char	*get_line(char	*big_line);
char	*get_big_line(int fd, char *str);

#endif
