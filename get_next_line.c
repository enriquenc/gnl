/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:16:18 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/09 21:44:53 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_bufer	*do_smth(t_bufer **list, int fd)
{
	if (!(*list))
	{
		if (!((*list) = (t_bufer *)malloc(sizeof(t_bufer))))
			return (NULL);
		(*list)->fd = fd;
		(*list)->buf = NULL;
		(*list)->next = NULL;
	}
	while ((*list)->next)
	{
		if ((*list)->fd == fd)
			break ;
		(*list) = (*list)->next;
	}
	if ((*list)->fd != fd)
	{
		if (!((*list)->next = (t_bufer *)malloc(sizeof(t_bufer))))
			return (NULL);
		(*list) = (*list)->next;
		(*list)->fd = fd;
		(*list)->buf = NULL;
		(*list)->next = NULL;
	}
	return (*list);
}

int		check_smth(t_bufer **list, char **res, char *buf)
{
	char *temp;
	char *pointer;

	if (buf == NULL)
		return (0);
	if ((temp = ft_strchr(buf, '\n')) == NULL)
	{
		(*res) = ft_strjoin(*res, buf);
		(*list)->buf = NULL;
	}
	else
	{
		pointer = ft_strsub(buf, 0, temp - buf);
		(*res) = ft_strjoin(*res, pointer);
		temp++;
		if (*temp == '\0')
			(*list)->buf = NULL;
		else
			(*list)->buf = ft_strdup(temp);
		free(pointer);
		*pointer = 0;
		return (1);
	}
	return (0);
}

int		do_smth2(t_bufer **s_list, t_bufer **list, char **line, int fd)
{
	t_bufer	*temp;
	char	buf[1];

	temp = NULL;
	if (*s_list)
		temp = *s_list;
	if (fd < 0 || !(*list = do_smth(s_list, fd))
		|| read(fd, buf, 0) < 0 || line == NULL)
		return (-1);
	if (temp)
		*s_list = temp;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			*buf;
	static	t_bufer	*s_list = NULL;
	int				read_bytes;
	t_bufer			*list;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1)))
		|| do_smth2(&s_list, &list, line, fd) == -1)
		return (-1);
	*line = NULL;
	if (check_smth(&list, line, list->buf))
		return (1);
	while ((read_bytes = read(fd, buf, BUFF_SIZE)))
	{
		if (read_bytes < 0)
			return (-1);
		buf[read_bytes] = '\0';
		if (check_smth(&list, line, buf))
			break ;
	}
	if (!read_bytes && !(*line))
		return (0);
	return (1);
}
