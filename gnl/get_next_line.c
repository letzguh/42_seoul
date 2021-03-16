/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <sohelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:19:37 by sohelee           #+#    #+#             */
/*   Updated: 2020/10/31 16:41:24 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			find_id(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char			get_a_line(char **s, char **line, int i)
{
	char	*tmp;

	if (!(*line = ft_substr(*s, 0, i)))
		return (-1);
	tmp = ft_strdup(&(*s)[i + 1]);
	free(*s);
	*s = tmp;
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char	*s[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			size;
	int			i;

	if (fd < 0 || line == 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (s[fd] && (((i = find_id(s[fd], '\n')) != -1)))
		return (get_a_line(&s[fd], line, i));
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		s[fd] = ft_strjoin(s[fd], buf);
		if (((i = find_id(s[fd], '\n')) != -1))
			return (get_a_line(&s[fd], line, i));
	}
	if (s[fd])
	{
		*line = ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = NULL;
		return (size);
	}
	*line = ft_strdup("");
	return (size);
}
