/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:16:18 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/03 16:16:20 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_bufer *do_smth(t_bufer **list, int fd)
{
    
    while ((*list) && (*list)->next)
    {
            if((*list)->fd == fd)
                break;
            (*list) = (*list)->next;
    }
    if (!(*list) || (*list)->fd != fd)
    {
        (*list) = (t_bufer *)malloc(sizeof(t_bufer));
        (*list)->fd = fd;
        (*list)->buf = NULL;
        (*list)->next = NULL;
    }
    return (*list);
}

int check_smth(t_bufer **list, char **res, char *buf)
{
    char *temp;

    if (buf == NULL)
        return 0;
    if ((temp = ft_strchr(buf, '\n')) == NULL)
    {
        (*res) = ft_strjoin(*res, buf);
        (*list)->buf = NULL;
    }
    else
    {
        (*res) = ft_strjoin(*res, ft_strsub(buf, 0, temp - buf));
        (*list)->buf = ft_strsub(buf , temp - buf + 1, BUFF_SIZE - (temp - buf) - 1);
        return 1;
    }
    return 0;
}

int get_next_line(const int fd, char **line)
{
    char buf[BUFF_SIZE + 1];
    char *res;
    static t_bufer *s_list;
    int read_bytes;
    t_bufer *list;

    res = NULL;
    list = do_smth(&s_list, fd);
    if (list->buf)
        check_smth(&list, &res, list->buf);
    while((read_bytes = read(fd, buf, BUFF_SIZE)))
    {
        if (check_smth(&list, &res, buf))
            break;
    }
    if (!read_bytes && !res)
         return 0;
    *line = res;
    return (1);
}



