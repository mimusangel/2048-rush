/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 22:00:52 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/19 17:34:53 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static t_fdline	*newfdl(int const fd, t_fdline *f)
{
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			ret;
	t_fdline	*fdl;

	str = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
	}
	if (ret == -1)
		return (NULL);
	if (!(fdl = (t_fdline *)malloc(sizeof(t_fdline))))
		return (NULL);
	fdl->fd = fd;
	fdl->lines = str;
	fdl->next = f;
	return (fdl);
}

int				getline(t_fdline *f, char **line)
{
	size_t	i;
	char	*tmp;

	*line = NULL;
	i = 0;
	while (f->lines && f->lines[i])
	{
		if (f->lines[i] == '\n')
		{
			*line = ft_strsub(f->lines, 0, i);
			tmp = f->lines;
			f->lines = ft_strsub(f->lines, i + 1, ft_strlen(f->lines) - i - 1);
			free(tmp);
			return (1);
		}
		i++;
	}
	if (f->lines)
		*line = ft_strdup(f->lines);
	f->fd = -1;
	f->lines = NULL;
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_fdline *fdl = NULL;
	t_fdline		*f;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!fdl)
		if (!(fdl = newfdl(fd, NULL)))
			return (-1);
	f = fdl;
	while (f->next && f->fd != fd)
		f = f->next;
	if (f->fd != fd)
	{
		f->next = newfdl(fd, f->next);
		f = f->next;
	}
	if (f)
		return (getline(f, line));
	return (-1);
}
