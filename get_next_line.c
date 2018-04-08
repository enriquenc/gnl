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

t_bufer *do_smth(t_bufer **list, int fd)
{   
    if (!(*list))
    {
        if(!(*list = (t_bufer *)malloc(sizeof(t_bufer))))
            return NULL;
        (*list)->fd = fd;
        (*list)->buf = NULL;
        (*list)->next = NULL;
        return (*list);
    }
    if((*list)->fd == fd)
        return (*list);
    while ((*list)->next)
    {
            if((*list)->fd == fd)
                return (*list);
            (*list) = (*list)->next;
    }
    if ((*list)->fd != fd)
    {
        if(!((*list)->next = (t_bufer *)malloc(sizeof(t_bufer))))
            return NULL;
        (*list) = (*list)->next;
        (*list)->fd = fd;
        (*list)->buf = NULL;
        (*list)->next = NULL;
    }
    return (*list);
}

int check_smth(t_bufer **list, char **res, char *buf)
{
    char *temp;
    char *pointer;

    if (buf == NULL)
        return 0;
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
        {
            temp--;
            (*list)->buf = ft_strsub(buf , temp - buf + 1, BUFF_SIZE - (temp - buf + 1));
        }
        free(pointer);
        *pointer = 0;
        return 1;
    }
    return 0;
}

int get_next_line(const int fd, char **line)
{
    char buf[BUFF_SIZE + 1];
    char *res;
    static t_bufer *s_list = NULL;
    int read_bytes;
    t_bufer *list;

    res = NULL;
    if (fd < 0 || !(list = do_smth(&s_list, fd)))
        return (-1);
    if (list->buf)
        if(check_smth(&list, &res, list->buf))
        {
            *line = res;
            return (1);
        }
    while((read_bytes = read(fd, buf, BUFF_SIZE)))
    {
        if (read_bytes < 0)
           return (-1);
        buf[read_bytes] = '\0';
        if (check_smth(&list, &res, buf))
            break;
    }
    if (!read_bytes && !res)
        return 0;
    *line = res;
    return (1);
}



